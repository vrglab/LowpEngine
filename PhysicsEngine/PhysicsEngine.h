/* ======================================================================================== */
/* LowpEngine - Physics Engine C/C++ header file.											*/
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>
#include <Core/Debugging/Debug.h>
#include <Core/Application/ApplicationInfo.h>

#include <ode/ode.h>

class PhysicsEngine
{
public:
	static void Init(Ref<ApplicationInfo>);
	static dWorldID CreatePhysicsWorld();
	static void Simulate();
	static void Cleanup();
};

