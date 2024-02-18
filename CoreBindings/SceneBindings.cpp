#include "pch.h"
#include "SceneBindings.h"
#include <Core/Debugging/Debug.h>

LP_Extern LP_Export inline SceneInstance* GetCurrentScene()
{
	return SceneManager::GetCurrentScene().get();
}

LP_Extern LP_Export inline GameObjectInstance* InstantiateGameObject(bool data, uintptr_t obj)
{
	return SceneManager::GetCurrentScene()->CreateInstance(data, obj);
}
