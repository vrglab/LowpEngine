#include "pch.h"
#include "SceneManager.h"

#include <Core/Debugging/Debug.h>

void SceneManager::Init(std::string scene_list_file)
{
	LP_CORE_INFO("Starting Scene Engine");
	current_scene = CreateRef<SceneInstance>();
	current_scene->CreateInstance();
	current_scene->CreateInstance();
	current_scene->CreateInstance();
	current_scene->CreateInstance();
}
