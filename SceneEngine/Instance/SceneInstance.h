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
	void CreateInstance(GameObject);
	void CreateInstance();
	void* GetConfig(std::string);
	void SetConfig(std::string, void*);
};