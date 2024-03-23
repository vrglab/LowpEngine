/* ======================================================================================== */
/* LowpEngine - Scripting Engine C/C++ header file.											*/
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>
#include <SceneEngine/Serialized/Component/Component.h>
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
LP_Extern LP_API MonoAssembly* game_assembly;
LP_Extern LP_API MonoImage* game_image;
LP_Extern LP_API MonoAssembly* game_assembly;
LP_Extern LP_API MonoImage* api_image;
LP_Extern LP_API MonoAssembly* api_assembly;

/**
 * @brief Main class for runtime's scripting engine (specifically used for basis of handling C#)
 */
class LP_API GameScripting
{
public:
	/**
	 * @brief Starts the runtimes scripting engine
	 * @param info the starting application configuration
	 */
	static void Init(Ref<ApplicationInfo> info);

	/**
	 * @brief Shuts down the scripting engine and cleans the memory
	 */
	static void ShutdownMono();

	/**
	 * @brief Creates a new C# instance for a serialized component
	 * @param component The serialized component
	 * @param parent_game_obj The parent Game object
	 * @return The created C# instance
	 */
	static MonoObject* CreateComponentClass(Component component, MonoObject* parent_game_obj);

	/**
	 * @brief Creates a C# instance of a GameObject using it's c++ instance
	 * @param gameobj The c++ instance GameObject
	 * @return The created C# instance
	 */
	static MonoObject* CreateGameObjectClass(GameObjectInstance* gameobj);

	/**
	 * @brief Finds a C# class in the Game Assembly
	 * @param id engine id of the class
	 * @return The found class
	 */
	static MonoClass* GetGameLoadedClassType(std::string id);

	/**
	 * @brief Finds a C# class in the Engine API Assembly
	 * @param id engine id of the class
	 * @return The found class
	 */
	static MonoClass* GetApiLoadedClassType(std::string id);

	/**
	 * @brief Finds a C# class based on it's engine id
	 * @param id engine id of the class
	 * @return The found class
	 */
	static MonoClass* GetClass(std::string id);
};

