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

#include <physx/PxPhysics.h>
#include <physx/PxPhysicsAPI.h>

using namespace physx;

// PhysX objects
LP_Extern LP_API PxDefaultAllocator gAllocator;
LP_Extern LP_API PxDefaultErrorCallback gErrorCallback;
LP_Extern LP_API PxFoundation* gFoundation;
LP_Extern LP_API PxPhysics* gPhysics;
LP_Extern LP_API PxDefaultCpuDispatcher* gDispatcher;

class PhysicsEngine
{
public:
	static void Init(Ref<ApplicationInfo>);
	static PxScene* CreatePhysicsWorld();
	static void Simulate();
	static void Cleanup();
};

