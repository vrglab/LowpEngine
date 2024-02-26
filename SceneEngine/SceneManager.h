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
#include <cereal/archives/binary.hpp>

#include "Instance/SceneInstance.h"
#include "Serialized/Scene.h"

LP_Extern LP_API std::vector<Scene> loaded_scenes;
LP_Extern LP_API Ref<SceneInstance> current_scene;

#ifdef EDITOR
#include "Instance/EditorPageInstance.h"
#include <ScriptingEngine/EditorPageType.h>
#include <ScriptingEngine/EditorScripting.h>
LP_Extern LP_API std::vector<Ref<EditorPageInstance>> created_pages;
#endif

class SceneManager
{

private:
	static Ref<SceneInstance> CreateSceneInstance(Scene);

public:
	static void Init(Ref<ApplicationInfo>);
	static inline Ref<SceneInstance> GetCurrentScene() 
	{
		return current_scene;
	};
#ifdef EDITOR
	static Ref<EditorPageInstance> CreatePageInstance(EditorPageType);
#endif
};

LP_API void GenerateSceneListFile(std::string, std::vector<Scene>);
