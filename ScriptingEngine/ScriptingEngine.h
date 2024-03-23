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

/**
 * @brief The engine's Main Scripting engine
 */
class LP_API ScriptingEngine
{
public:

	/**
	 * @brief Starts the scripting engine
	 * @param info the starting application configuration
	 */
	static void InitMono(Ref<ApplicationInfo> info);

	/**
	 * @brief Shuts down the scripting engine and cleans the memory
	 */
	static void ShutdownMono();

	/**
	 * @return The primary mono domain started
	 */
	static MonoDomain* GetCurrentDomain();
};

