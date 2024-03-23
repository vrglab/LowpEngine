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

#include <mono/metadata/debug-helpers.h>
#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>
#include <mono/metadata/mono-config.h>
#include <filesystem>

#include <SceneEngine/Instance/GameObjectInstance.h>

#include <EventEngine/EventEngine.h>

#include "ScriptsDatabase.h"

namespace fs = std::filesystem;

LP_Extern LP_API MonoDomain* monoDomain;
LP_Extern LP_API std::vector<MonoAssembly*> loaded_assemblies;
LP_Extern LP_API ScriptsDatabase database;
LP_Extern LP_API MonoAssembly* editor_assembly;
LP_Extern LP_API MonoImage* editor_image;

/**
 * @brief Main class for editor time's scripting engine (specifically used for basis of handling C# editor page creation"
 */
class LP_API EditorScripting
{
public:
	/**
	 * @brief Starts the editors Scripting Engine
	 */
	static void Init();

	/**
	 * @brief Shuts down the scripting engine and cleans the memory
	 */
	static void ShutdownMono();

	/**
	 * @brief Get's the c# class type of the requested page 
	 * @param id The requested pages systematic id
	 * @return The found C# class
	 */
	static MonoClass* GetPage(std::string id);

	/**
	 * @brief Get's the requested pages type based on it's systematic id 
	 * @param id The id of the requested page type
	 * @return The found page type
	 */
	static EditorPageType GetPageType(std::string id);

	/**
	 * @brief Creates a C# page instance based on it's page type
	 * @param type The page type to create a C# instance for
	 * @return The created C# instance
	 */
	static MonoObject* CreatePageInstance(EditorPageType type);

	/**
	 * @return A list of all available pages to be opened
	 */
	static std::vector<std::string> GetPages();
};

