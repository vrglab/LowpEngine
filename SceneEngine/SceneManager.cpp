#include "pch.h"
#include "SceneManager.h"

#include <Core/Debugging/Debug.h>

void SceneManager::Init(std::string scene_list_file)
{
	LP_CORE_INFO("Starting Scene Engine");
	current_scene = CreateRef<SceneInstance>();

	float* clearColor = new float[4] { 0.4f, 0.4f, 1.0f, 0.5f };
	current_scene->SetConfig("bgd_color", clearColor);
}