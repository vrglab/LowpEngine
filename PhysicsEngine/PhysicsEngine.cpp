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

void PhysicsEngine::Simulate()
{
	dWorldStep((dWorldID)current_scene->GetConfig("phys_world"), 0.01);
}

void PhysicsEngine::Cleanup()
{
	dWorldDestroy((dWorldID)current_scene->GetConfig("phys_world"));
	dCloseODE();
}
