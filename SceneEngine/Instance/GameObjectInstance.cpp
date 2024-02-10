#include "pch.h"
#include "GameObjectInstance.h"
#include <ScriptingEngine/ScriptingEngine.h>

void GameObjectInstance::Awake()
{
	for (size_t i = 0; i < base.components.size(); i++)
	{
		Component component = base.components[i];

		ComponentInstance instance = {};
		instance.parent = base;
		instance.base = component;
		instance.created_instance = ScriptingEngine::CreateComponentClass(component);
		component_instances.push_back(instance);
	}
}
