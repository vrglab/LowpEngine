/* ======================================================================================== */
/* LowpEngine - Scene Engine C/C++ header file.										        */
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>

#include "Instance/SceneInstance.h"
#include "Serialized/Scene.h"

LP_Extern LP_API std::vector<Scene> loaded_scenes;
LP_Extern LP_API Ref<SceneInstance> current_scene;

class SceneManager
{
public:
	static void Init(std::string);
	static inline Ref<SceneInstance> GetCurrentScene() 
	{
		return current_scene;
	};
};

