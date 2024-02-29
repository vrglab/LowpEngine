#include "pch.h"
#include "PhysicsEngine.h"

PxDefaultAllocator gAllocator;
PxDefaultErrorCallback gErrorCallback;
PxFoundation* gFoundation = nullptr;
PxPhysics* gPhysics = nullptr;
PxDefaultCpuDispatcher* gDispatcher = nullptr;

void PhysicsEngine::Init(Ref<ApplicationInfo> info)
{
	LP_CORE_INFO("Starting Physics Engine");
    gFoundation = PxCreateFoundation(PX_PHYSICS_VERSION, gAllocator, gErrorCallback);
    gPhysics = PxCreatePhysics(PX_PHYSICS_VERSION, *gFoundation, PxTolerancesScale(), true);
    gDispatcher = PxDefaultCpuDispatcherCreate(2);
}

PxScene* PhysicsEngine::CreatePhysicsWorld()
{
    PxSceneDesc sceneDesc(gPhysics->getTolerancesScale());
    sceneDesc.gravity = PxVec3(0.0f, -9.81f, 0.0f);
    sceneDesc.cpuDispatcher = gDispatcher;
    sceneDesc.filterShader = PxDefaultSimulationFilterShader;
    return gPhysics->createScene(sceneDesc);
}

void PhysicsEngine::Simulate()
{
}

void PhysicsEngine::Cleanup()
{
    gDispatcher->release();
    gPhysics->release();
    gFoundation->release();
}
