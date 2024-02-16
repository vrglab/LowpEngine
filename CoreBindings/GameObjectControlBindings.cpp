#include "pch.h"
#include "GameObjectControlBindings.h"

LP_Extern LP_Export char* GetGameOBJName(GameObjectInstance* obj)
{
    return (char*)obj->base.Name.c_str();
}

LP_Extern LP_Export void SetGameOBJName(GameObjectInstance* obj, char* name)
{
    obj->base.Name = name;
}
