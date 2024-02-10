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

class SceneInstance
{
private:
	std::vector<GameObjectInstance> obj_instances;
public:
	Scene base;
	void CreateInstance();
};