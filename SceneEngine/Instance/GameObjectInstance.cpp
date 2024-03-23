#include "pch.h"
#include "GameObjectInstance.h"
#include <ScriptingEngine/ScriptingEngine.h>

void GameObjectInstance::CreateComponentInstance(Component component)
{
#ifdef GAME
	component_instances.push_back({ 
		component, 
		reinterpret_cast<uintptr_t>(this),
		GameScripting::GetClass(component.engine_id), 
		GameScripting::CreateComponentClass(component, obj_instance) 
		});
#endif
}

void GameObjectInstance::Awake()
{
	for (size_t i = 0; i < base.components.size(); i++)
	{
		CreateComponentInstance(base.components[i]);
	}
}

void GameObjectInstance::Update()
{
	for (size_t i = 0; i < component_instances.size(); i++)
	{
		component_instances[i].Update();
	}
}
