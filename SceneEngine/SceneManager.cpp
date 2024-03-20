#include "pch.h"
#include "SceneManager.h"

#include <Core/Debugging/Debug.h>

#include <iostream>
#include <filesystem>
#include <fstream>

#include <PhysicsEngine/PhysicsEngine.h>

std::vector<Scene> loaded_scenes;
Ref<SceneInstance> current_scene;
#ifdef EDITOR
std::vector<Ref<EditorPageInstance>> created_pages;
#endif

Ref<SceneInstance> SceneManager::CreateSceneInstance(Scene base)
{
	Ref<SceneInstance> _instance = CreateRef<SceneInstance>();
	_instance->base = base;

	_instance->configs.SetConfig("phys_world", PhysicsEngine::CreatePhysicsWorld());
	_instance->configs.SetConfig("phys_space", PhysicsEngine::CreatePhysicsSpace());

	float* clearColor = new float[4] { 0.4f, 0.4f, 1.0f, 0.5f };
	_instance->configs.SetConfig("bgd_color", clearColor);

	return _instance;
}

void SceneManager::InitializeSceneObjects(Ref<SceneInstance> scene)
{
	for (size_t i = 0; i < scene->base.game_objects.size(); i++)
	{
		scene->CreateInstance(scene->base.game_objects[i]);
	}
}

void SceneManager::Init(Ref<ApplicationInfo> info)
{
	LP_CORE_INFO("Starting Scene Engine");
#ifdef GAME
	current_scene = CreateRef<SceneInstance>();
	current_scene->Init();


	std::string levels_file = info->ResourcesDir;
	levels_file.append("\\levels_table.bin");
	std::ifstream is_level_file(levels_file, std::ios::binary);
	if (is_level_file.good())
	{
		cereal::BinaryInputArchive archive(is_level_file);
		archive(loaded_scenes);
	}

	SetCurrentScene(loaded_scenes[0]);
#endif
#ifdef EDITOR
	current_scene = CreateRef<SceneInstance>();
	current_scene->Init();
#endif
}

void SceneManager::SetCurrentScene(Scene scene)
{
	current_scene = CreateSceneInstance(scene);
	InitializeSceneObjects(current_scene);
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

#ifdef EDITOR
Ref<EditorPageInstance> SceneManager::CreatePageInstance(EditorPageType page)
{
	Ref<EditorPageInstance> ref = CreateRef<EditorPageInstance>();
	ref->page_type = page;
	ref->id = GUIDGen();
	ref->instance = EditorScripting::CreatePageInstance(page);
	created_pages.push_back(ref);
	return ref;
}
#endif