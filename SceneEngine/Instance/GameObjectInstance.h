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

/**
 * @brief Runtime instance of a GameObject
 */
class GameObjectInstance
{
public:
	MonoObject* obj_instance;
	std::vector<ComponentInstance> component_instances;
	GameObject base;

	/**
	 * @brief Creates a component instance using it's serialized version and add's it to the Game Object instance
	 * @param serialized_component The serialized component
	 */
	void CreateComponentInstance(Component serialized_component);

	/**
	 * @brief Creates a Component instance for all of the serialized components within the serialized game object
	 */
	void Awake();

	/**
	 * @brief Update call of the GameObject which
	 *		  calls all of the object components Update function
	 */
	void Update();
};