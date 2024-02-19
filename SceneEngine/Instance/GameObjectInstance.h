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


class GameObjectInstance
{
private:
	void CreateComponentInstance(Component);

public:
	MonoObject* obj_instance;
	std::vector<ComponentInstance> component_instances;
	GameObject base;
	void Awake();
	void Update();
};