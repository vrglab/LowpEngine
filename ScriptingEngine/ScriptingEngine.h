/* ======================================================================================== */
/* LowpEngine - Scripting Engine C/C++ header file.											*/
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>
#include <Core/Application/ApplicationInfo.h>

#ifdef GAME
#include "GameScripting.h"
#endif
#ifdef EDITOR
#include "EditorScripting.h"
#endif

class LP_API ScriptingEngine
{
public:
	static void InitMono(Ref<ApplicationInfo>);
	static void ShutdownMono();
	static MonoDomain* GetCurrentDomain();
};

