#include "pch.h"
#include "SceneInstance.h"

void SceneInstance::CreateInstance(GameObject obj_data)
{
	Ref<GameObjectInstance> created_instance = CreateRef<GameObjectInstance>();
	created_instance->base = obj_data;
	created_instance->Awake();
}

void SceneInstance::CreateInstance()
{
	Ref<GameObjectInstance> created_instance = CreateRef<GameObjectInstance>();
	GameObject obj = {};
	obj.Name = "GameObject";
	obj.guid = GUIDGen();
	created_instance->base = obj;
	created_instance->Awake();
}