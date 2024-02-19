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
};

LP_API void GenerateSceneListFile(std::string, std::vector<Scene>);
