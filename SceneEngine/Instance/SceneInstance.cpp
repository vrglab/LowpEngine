#include "pch.h"
#include "SceneInstance.h"

void SceneInstance::CreateInstance(GameObject obj_data)
{
	Ref<GameObjectInstance> created_instance = CreateRef<GameObjectInstance>();
	created_instance->base = obj_data;
	created_instance->Awake();
}
