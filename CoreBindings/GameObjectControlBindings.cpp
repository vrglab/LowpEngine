#include "pch.h"
#include "GameObjectControlBindings.h"

LP_Extern LP_BINDINGS_API char* GetGameOBJName(GameObjectInstance* obj)
{
    return obj->base.Name.data();
}

LP_Extern LP_BINDINGS_API void SetGameOBJName(GameObjectInstance* obj, char* name)
{
    obj->base.Name = name;
}

LP_Extern LP_BINDINGS_API char* GetGameOBJId(GameObjectInstance* obj)
{
    return obj->base.guid.data();
}

LP_Extern LP_BINDINGS_API void AddComponentToObj(GameObjectInstance* obj, char* comp_id)
{
	Component comp = {};
	comp.engine_id = comp_id;

	ComponentInstance instance = {};
	instance.parent = reinterpret_cast<uintptr_t>(obj);
	instance.base = comp;
	instance.created_instance = GameScripting::CreateComponentClass(comp, obj->obj_instance);
	MonoClass* klass = GameScripting::GetGameLoadedClassType(comp.engine_id);
	if (!klass) {
		klass = GameScripting::GetApiLoadedClassType(comp.engine_id);
	}
	instance.class_type = klass;
	obj->component_instances.push_back(instance);
}
