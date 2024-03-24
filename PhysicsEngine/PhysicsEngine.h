/* ======================================================================================== */
/* LowpEngine - Physics Engine C/C++ header file.											*/
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>
#include <Core/Application/ApplicationInfo.h>

#include <ode/ode.h>

/**
 * @brief The main class in charge of handling the games runtime Physics
 */
class PhysicsEngine
{
public:
	/**
	 * @brief Starts the Physics engine
	 * @param info The starting configs of the application
	 */
	static void Init(Ref<ApplicationInfo> info);

	/**
	 * @brief Initiates a new Physics world every time it's called
	 * @return The created physics world 
	 */
	static dWorldID CreatePhysicsWorld();

	/**
	 * @brief Creates a new Collision space every time it's called
	 * @return The created collision space
	 */
	static dSpaceID CreatePhysicsSpace();

	/**
	 * @brief Runs a step in the physics simulation every time its called
	 */
	static void Simulate();

	/**
	 * @brief Cleans up the memory from the Physics engine upon being called
	 */
	static void Cleanup();
};

