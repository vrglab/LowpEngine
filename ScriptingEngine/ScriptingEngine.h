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

#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>
#include <mono/metadata/mono-config.h>

#include <filesystem>

namespace fs = std::filesystem;

#if _WIN32
#define ASSEMBLY_EXTENSION ".dll"
#elif defined(__linux__)
#define ASSEMBLY_EXTENSION ".so"
#elif defined(__APPLE__)
#define ASSEMBLY_EXTENSION ".dylib"
#endif

LP_Export class ScriptingEngine
{
private:
	static inline MonoDomain* monoDomain;
	static inline std::vector<MonoAssembly*> loaded_assemblies;

public:
	static MonoAssembly* LoadAssembly(std::string assemblyPath);
	static void LoadAllAssembliesFromDirectory(std::string directoryPath);
	static void InitMono(Ref<ApplicationInfo>);
	static void ShutdownMono();
};

