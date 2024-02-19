#include "pch.h"
#include "SceneInstance.h"
#include <ScriptingEngine/ScriptingEngine.h>
#include <Core/Debugging/Debug.h>

void SceneInstance::CreateInstance(GameObject obj_data)
{
	Ref<GameObjectInstance> created_instance = CreateRef<GameObjectInstance>();
	created_instance->base = obj_data;
	created_instance->obj_instance = ScriptingEngine::CreateGameObjectClass(created_instance.get());
	created_instance->Awake();
	obj_instances.push_back(created_instance);
}

GameObjectInstance* SceneInstance::CreateInstance(bool instatiate_in_sharp, uintptr_t _obj)
{
	Ref<GameObjectInstance> created_instance = CreateRef<GameObjectInstance>();
	GameObject obj = {};
	obj.Name = "GameObject";
	obj.guid = GUIDGen();

	Component transform = {};
	transform.engine_id = "Transform";
	obj.components.push_back(transform);

	created_instance->base = obj;
	if (instatiate_in_sharp) {
		created_instance->obj_instance = ScriptingEngine::CreateGameObjectClass(created_instance.get());
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
}

void* SceneInstance::GetConfig(std::string id)
{
	for (size_t i = 0; i < configs.size(); i++)
	{
		if (configs[i].id == id) {
			return configs[i].value;
		}
	}
	return nullptr;
}

void SceneInstance::SetConfig(std::string id, void* val)
{
	for (size_t i = 0; i < configs.size(); i++)
	{
		if (configs[i].id == id) {
			configs[i].value = val;
			return;
		}
	}

	SceneInstanceConfigs sic = {};
	sic.id = id;
	sic.value = val;
	configs.push_back(sic);
}
