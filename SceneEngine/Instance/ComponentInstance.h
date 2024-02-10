/* ======================================================================================== */
/* LowpEngine - Scene Engine C/C++ header file.										        */
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>
#include <Mono/metadata/object.h>

#include "SceneEngine/Serialized/Component/Component.h"
#include "Serialized/GameObject.h"

LP_Export class ComponentInstance
{
public:
	Component base;
	GameObject parent;
	MonoObject* created_instance;
};

