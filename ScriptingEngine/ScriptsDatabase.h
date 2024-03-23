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

/**
 * @brief Database containing engines loaded page/c# script types
 */
class ScriptsDatabase
{
public:
#ifdef GAME
	std::vector<LoadedScript> scripts;

	/**
	 * @brief Finds and returns a memory loaded C# script type based on it's engine id
	 * @param id The engine if of the script
	 * @return the found script, nullptr if nothing found
	 */
	MonoClass* GetLoadedScript(std::string id);
#endif
#ifdef EDITOR
	std::vector<EditorPageType> scripts;
	/**
	 * @brief Finds and returns a memory loaded C# script type based on it's engine id
	 * @param id The engine if of the script
	 * @return the found script, nullptr if nothing found
	 */
	MonoClass* GetLoadedScript(std::string id);

	/**
	 * @brief Finds and returns a memory loaded page type based on it's engine id
	 * @param id The engine if of the page
	 * @return the found page, nullptr if nothing found
	 */
	EditorPageType GetLoadedPageType(std::string id);
#endif
};

