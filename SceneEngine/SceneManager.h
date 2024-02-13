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

class SceneManager
{
private:
	static inline std::vector<Scene> loaded_scenes;
	static inline Ref<SceneInstance> current_scene;
public:
	static void Init(std::string);
	
};

