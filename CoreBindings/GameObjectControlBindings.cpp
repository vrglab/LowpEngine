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
#ifdef GAME
	Component comp = {};
	comp.engine_id = comp_id;

	obj->CreateComponentInstance(comp);
#endif
}
