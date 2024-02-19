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

class ComponentInstance
{
public:
	Component base;
	uintptr_t parent;
	MonoClass* class_type;
	MonoObject* created_instance;
	void Update();
};

