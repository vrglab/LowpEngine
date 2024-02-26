#include "pch.h"
#include "GameObjectInstance.h"
#include <ScriptingEngine/ScriptingEngine.h>

void GameObjectInstance::CreateComponentInstance(Component component)
{
#ifdef GAME
	ComponentInstance instance = {};
	instance.parent = reinterpret_cast<uintptr_t>(this);
	instance.base = component;
	instance.created_instance = GameScripting::CreateComponentClass(component, obj_instance);
	MonoClass* klass = GameScripting::GetGameLoadedClassType(component.engine_id);
	if (!klass) {
		klass = GameScripting::GetApiLoadedClassType(component.engine_id);
	}
	instance.class_type = klass;
	component_instances.push_back(instance);
#endif
}

void GameObjectInstance::Awake()
{
	for (size_t i = 0; i < base.components.size(); i++)
	{
		Component component = base.components[i];
		CreateComponentInstance(component);
	}
}

void GameObjectInstance::Update()
{
	for (size_t i = 0; i < component_instances.size(); i++)
	{
		component_instances[i].Update();
	}
}
