/* ======================================================================================== */
/* LowpEngine - Scripting Engine C/C++ header file.											*/
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>
#include <Core/Debugging/Debug.h>
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
LP_Extern LP_API MonoAssembly* editor_assembly;
LP_Extern LP_API MonoImage* editor_image;

class EditorScripting
{
private:
	static bool IsSubclassOf(MonoClass*, MonoClass*);

public:
	static void Init();
	static void ShutdownMono();
	static MonoAssembly* LoadAssembly(std::string assemblyPath);
	static void LoadAllAssembliesFromDirectory(std::string directoryPath);
	static MonoClass* GetPage(std::string id);
	static EditorPageType GetPage_(std::string id);
	static MonoObject* CreatePageInstance(EditorPageType);
	static std::vector<std::string> GetPages();
};

