#include "pch.h"
#include "GameObjectControlBindings.h"

LP_Extern LP_BINDINGS_API char* GetGameOBJName(GameObjectInstance* obj)
{
    return (char*)obj->base.Name.c_str();
}

LP_Extern LP_BINDINGS_API void SetGameOBJName(GameObjectInstance* obj, char* name)
{
    obj->base.Name = name;
}
