/* ======================================================================================== */
/* LowpEngine - Scripting Engine C/C++ header file.											*/
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>
#include <Core/Application/ApplicationInfo.h>
#include <SceneEngine/Serialized/Component/Component.h>

#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>
#include <mono/metadata/mono-config.h>

#include <filesystem>

#include <SceneEngine/Instance/GameObjectInstance.h>

#include "ScriptsDatabase.h"

namespace fs = std::filesystem;

#if _WIN32
#define ASSEMBLY_EXTENSION ".dll"
#elif defined(__linux__)
#define ASSEMBLY_EXTENSION ".so"
#elif defined(__APPLE__)
#define ASSEMBLY_EXTENSION ".dylib"
#endif

LP_Extern LP_API MonoDomain* monoDomain;
LP_Extern LP_API MonoImage* game_image;
LP_Extern LP_API MonoImage* api_image;
LP_Extern LP_API MonoAssembly* api_assembly;
LP_Extern LP_API MonoAssembly* game_assembly;
LP_Extern LP_API std::vector<MonoAssembly*> loaded_assemblies;
LP_Extern LP_API ScriptsDatabase database;


class ScriptingEngine
{
private:
	static bool IsSubclassOf(MonoClass*, MonoClass*);

public:
	static MonoAssembly* LoadAssembly(std::string assemblyPath);
	static void LoadAllAssembliesFromDirectory(std::string directoryPath);
	static void InitMono(Ref<ApplicationInfo>);
	static void ShutdownMono();
	static MonoObject* CreateComponentClass(Component, MonoObject*);
	static MonoObject* CreateGameObjectClass(GameObjectInstance*);
	static MonoClass* GetGameLoadedClassType(std::string);
	static MonoClass* GetApiLoadedClassType(std::string);
};

