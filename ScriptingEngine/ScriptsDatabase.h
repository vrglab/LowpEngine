/* ======================================================================================== */
/* LowpEngine - Scripting Engine C/C++ header file.											*/
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>
#include "LoadedScript.h"
#include "EditorPageType.h"

class ScriptsDatabase
{
public:
#ifdef GAME
	std::vector<LoadedScript> scripts;
	MonoClass* GetLoadedScript(std::string);
#endif
#ifdef EDITOR
	std::vector<EditorPageType> scripts;
	MonoClass* GetLoadedScript(std::string);
	EditorPageType GetLoadedScript_(std::string);
#endif
};

