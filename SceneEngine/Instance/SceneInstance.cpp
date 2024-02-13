#include "pch.h"
#include "SceneInstance.h"

void SceneInstance::CreateInstance(GameObject obj_data)
{
	Ref<GameObjectInstance> created_instance = CreateRef<GameObjectInstance>();
	created_instance->base = obj_data;
	created_instance->Awake();
	obj_instances.push_back(created_instance);
}

void SceneInstance::CreateInstance()
{
	Ref<GameObjectInstance> created_instance = CreateRef<GameObjectInstance>();
	GameObject obj = {};
	obj.Name = "GameObject";
	obj.guid = GUIDGen();

	Component transform = {};
	transform.engine_id = "TestClass";
	obj.components.push_back(transform);

	created_instance->base = obj;
	created_instance->Awake();
	obj_instances.push_back(created_instance);
}