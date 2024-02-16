#include "pch.h"
#include "SceneInstance.h"

void SceneInstance::CreateInstance(GameObject obj_data)
{
	Ref<GameObjectInstance> created_instance = CreateRef<GameObjectInstance>();
	created_instance->base = obj_data;
	created_instance->Awake();
	obj_instances.push_back(created_instance);
}

GameObjectInstance* SceneInstance::CreateInstance()
{
	Ref<GameObjectInstance> created_instance = CreateRef<GameObjectInstance>();
	GameObject obj = {};
	obj.Name = "GameObject";
	obj.guid = GUIDGen();

	Component transform = {};
	transform.engine_id = "Transform";
	obj.components.push_back(transform);

	created_instance->base = obj;
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
