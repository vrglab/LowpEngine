#include "pch.h"
#include "SceneInstance.h"
#include <ScriptingEngine/ScriptingEngine.h>

void SceneInstance::CreateInstance(GameObject obj_data)
{
#ifdef GAME
	Ref<GameObjectInstance> created_instance = CreateRef<GameObjectInstance>();
	created_instance->base = obj_data;
	created_instance->obj_instance = GameScripting::CreateGameObjectClass(created_instance.get());
	created_instance->Awake();
	obj_instances.push_back(created_instance);
#endif
}

GameObjectInstance* SceneInstance::CreateInstance(bool instatiate_in_sharp, uintptr_t _obj)
{
#ifdef GAME
	Ref<GameObjectInstance> created_instance = CreateRef<GameObjectInstance>();
	GameObject obj = {};
	obj.Name = "GameObject";
	obj.guid = GUIDGen();

	Component transform = {};
	transform.engine_id = "Transform";
	obj.components.push_back(transform);

	created_instance->base = obj;
	if (instatiate_in_sharp) {
		created_instance->obj_instance = GameScripting::CreateGameObjectClass(created_instance.get());
	} else
	{
		created_instance->obj_instance = mono_gchandle_get_target(_obj);

		MonoClass* klass = mono_class_from_name(api_image, "LowpEngine", "GameObject");

		void* args[1];
		intptr_t myIntPtrValue = reinterpret_cast<uintptr_t>(created_instance.get());
		args[0] = &myIntPtrValue;

		MonoClassField* field = mono_class_get_field_from_name(klass, "instance_pointer");
		if (field) {
			mono_field_set_value(created_instance->obj_instance, field, &myIntPtrValue);
		}
		else {
			// Handle the error: Field not found
		}
	}
	created_instance->Awake();
	obj_instances.push_back(created_instance);
	return created_instance.get();
#endif
#ifdef EDITOR
	return nullptr;
#endif
}

void SceneInstance::Update()
{
	if (!obj_instances.empty()) {
		for (size_t i = 0; i < obj_instances.size(); i++)
		{
			obj_instances[i]->Update();
		}
	}
}

void SceneInstance::Init()
{
	obj_instances = {};
	configs = {};
}
