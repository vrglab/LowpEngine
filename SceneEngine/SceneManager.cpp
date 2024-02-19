#include "pch.h"
#include "SceneManager.h"

#include <Core/Debugging/Debug.h>

#include <iostream>
#include <filesystem>
#include <fstream>

std::vector<Scene> loaded_scenes;
Ref<SceneInstance> current_scene;

Ref<SceneInstance> SceneManager::CreateSceneInstance(Scene base)
{
	Ref<SceneInstance> _instance = CreateRef<SceneInstance>();
	_instance->base = base;
	
	for (size_t i = 0; i < base.game_objects.size(); i++)
	{
		_instance->CreateInstance(base.game_objects[i]);
	}

	float* clearColor = new float[4] { 0.4f, 0.4f, 1.0f, 0.5f };
	_instance->SetConfig("bgd_color", clearColor);

	return _instance;
}

void SceneManager::Init(Ref<ApplicationInfo> info)
{
	LP_CORE_INFO("Starting Scene Engine");
	current_scene = CreateRef<SceneInstance>();
	std::string levels_file = info->ResourcesDir;
	levels_file.append("\\levels_table.bin");
	std::ifstream is_level_file(levels_file, std::ios::binary);
	if (is_level_file.good())
	{
		cereal::BinaryInputArchive archive(is_level_file);
		archive(loaded_scenes);
	}

	current_scene = CreateSceneInstance(loaded_scenes[0]);
}

void GenerateSceneListFile(std::string filepath, std::vector<Scene> scene_list)
{
	std::ofstream  level_file_stream(filepath.append("levels_table.bin").c_str(), std::ios::binary);
	if (!level_file_stream.is_open()) {
		throw std::runtime_error("Failed to open Levels file for writing.");
	}
	cereal::BinaryOutputArchive archive_levle(level_file_stream);
	archive_levle(scene_list);
}