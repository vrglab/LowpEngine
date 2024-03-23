#include "pch.h"
#include "SceneInstance.h"
#include <ScriptingEngine/ScriptingEngine.h>

#include "ScriptingEngine/ScriptingUtils.h"

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
	GameObject obj = { GUIDGen(), "GameObject" };
	obj.components.push_back({ "Transform" });

	created_instance->base = obj;
	if (instatiate_in_sharp) {
		created_instance->obj_instance = GameScripting::CreateGameObjectClass(created_instance.get());
	} else
	{
		created_instance->obj_instance = mono_gchandle_get_target(_obj);

		void* args[1];
		intptr_t myIntPtrValue = reinterpret_cast<uintptr_t>(created_instance.get());
		args[0] = &myIntPtrValue;

		MonoClassField* field = mono_class_get_field_from_name(ScriptingUtils::GetClass("LowpEngine.GameObject", api_image), "instance_pointer");
		IFNERR(field, mono_field_set_value(created_instance->obj_instance, field, &myIntPtrValue);, "instance_pointer", "Not found in");
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
