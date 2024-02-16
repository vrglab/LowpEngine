#include "pch.h"
#include "SceneBindings.h"

LP_Extern LP_Export inline SceneInstance* GetCurrentScene()
{
	return SceneManager::GetCurrentScene().get();
}

LP_Extern LP_Export inline GameObjectInstance* InstantiateGameObject()
{
	return SceneManager::GetCurrentScene()->CreateInstance(true);
}
