/* ======================================================================================== */
/* LowpEngine - Scene Engine C/C++ header file.										        */
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>
#include <Core/Application/ApplicationInfo.h>

#include <cereal/cereal.hpp>

#include "Instance/SceneInstance.h"
#include "Serialized/Scene.h"

#ifdef EDITOR
#include "Instance/EditorPageInstance.h"
#include <ScriptingEngine/EditorPageType.h>
#include <ScriptingEngine/EditorScripting.h>
LP_Extern LP_API std::vector<Ref<EditorPageInstance>> created_pages;
#endif

LP_Extern LP_API std::vector<Scene> loaded_scenes;
LP_Extern LP_API Ref<SceneInstance> current_scene;

/**
 * @brief Primary class in charge of handling a runtime's scene
 *
 */
class LP_API SceneManager
{

private:
	/**
	 * @brief Creates a Scene instance based on it's serialized scene
	 * @param serialized_scene serialized Scene
	 * @return A Smart pointer to the SceneInstance
	 */
	static Ref<SceneInstance> CreateSceneInstance(Scene serialized_scene);

	/**
	 * @brief Initializes all of a Scene instances, GameObject instances based on it's internal serialized scene
	 * @param scene Smart pointer pointing to the scene
	 */
	static void InitializeSceneObjects(Ref<SceneInstance> scene);

public:
	/**
	 * @brief Starts the scene engine by loading all of the built scenes in the level_table.bin file
	 * @param info the starting application configuration
	 */
	static void Init(Ref<ApplicationInfo> info);

	/**
	 * @brief Unloads the currently loaded scene and loads the given as to become the new current scene
	 * @param scene The scene to load as the current scene
	 */
	static void SetCurrentScene(Scene scene);

	/**
	 * @brief gets the currently open scene
	 * @return a smart pointer pointing to the currently active scene
	 */
	static inline Ref<SceneInstance> GetCurrentScene() 
	{
		return current_scene;
	};
#ifdef EDITOR
	/**
	 * @brief Creates a new editor page instance based on the page type requested
	 * @param page_type The requested page type
	 * @return Smart pointer to the generated editor page instance
	 */
	static Ref<EditorPageInstance> CreatePageInstance(EditorPageType page_type);
#endif
};

/**
 * @brief Creates a new levels_table.bin file using the given scene list
 * @param filepath The location the file will be generated in
 * @param scene_list The list of scenes to serialize
 */
LP_API void GenerateSceneListFile(std::string filepath, std::vector<Scene> scene_list);




