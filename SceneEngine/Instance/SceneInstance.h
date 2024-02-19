/* ======================================================================================== */
/* LowpEngine - Scene Engine C/C++ header file.										        */
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>
#include "SceneEngine/Serialized/Scene.h"
#include "SceneEngine/Serialized/GameObject.h"
#include "GameObjectInstance.h"
#include "SceneInstanceConfigs.h"

class SceneInstance
{
private:
	std::vector<SceneInstanceConfigs> configs;
	std::vector<Ref<GameObjectInstance>> obj_instances;
public:
	Scene base;
	LP_API void CreateInstance(GameObject);
	LP_API GameObjectInstance* CreateInstance(bool instatiate_in_sharp, uintptr_t);
	LP_API void* GetConfig(std::string);
	LP_API void SetConfig(std::string, void*);
};