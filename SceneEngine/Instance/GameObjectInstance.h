/* ======================================================================================== */
/* LowpEngine - Scene Engine C/C++ header file.										        */
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>

#include "ComponentInstance.h"
#include "SceneEngine/Serialized/GameObject.h"


LP_Export class GameObjectInstance
{
private:
	MonoObject* obj_instance;
	std::vector<ComponentInstance> component_instances;
	void CreateComponentInstance(Component);

public:
	GameObject base;
	void Awake();
};