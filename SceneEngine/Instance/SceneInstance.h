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

/**
 * @brief Instance of a live and open scene in the runtime
 */
class LP_API SceneInstance
{
private:
	std::vector<Ref<GameObjectInstance>> obj_instances;
public:
	Scene base;
	Config configs;

	/**
	 * @brief Creates a GameObject instance based on the given serialized game object
	 * @param serialized_gameobj The serialized game object
	 */
	void CreateInstance(GameObject serialized_gameobj);

	/**
	 * @brief Creates a empty GameObject instance within the scene
	 * @param instantiate_in_sharp Set true to generate a C# instance of the GameObject. Set False to use a created C# instance as our own
	 * @param sharp_instance The given C# instance to use if needed
	 */
	GameObjectInstance* CreateInstance(bool instantiate_in_sharp, uintptr_t sharp_instance);

	/**
	 * @brief Calls all of the game object instances update functions
	 */
	void Update();

	/**
	 * @brief Helper function to initialize all of the scenes variables
	 */
	void Init();
};