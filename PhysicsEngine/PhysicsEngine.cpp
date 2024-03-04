#include "pch.h"
#include "PhysicsEngine.h"

#include <SceneEngine/SceneManager.h>

void PhysicsEngine::Init(Ref<ApplicationInfo> info)
{
	LP_CORE_INFO("Starting Physics Engine");
	dInitODE();
}

dWorldID PhysicsEngine::CreatePhysicsWorld()
{
	dWorldID world = dWorldCreate();
	dWorldSetGravity(world, 0, -9.81, 0);
	return world;
}

dSpaceID PhysicsEngine::CreatePhysicsSpace()
{
	return dSimpleSpaceCreate(0);
}

void PhysicsEngine::Simulate()
{
	dWorldStep((dWorldID)current_scene->GetConfig("phys_world"), 0.01);
}

void PhysicsEngine::Cleanup()
{
	dSpaceDestroy((dSpaceID)current_scene->GetConfig("phys_space"));
	dWorldDestroy((dWorldID)current_scene->GetConfig("phys_world"));
	dCloseODE();
}