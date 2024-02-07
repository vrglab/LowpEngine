#include "pch.h"
#include "ScriptingEngine.h"
#include <Core/Debugging/Debug.h>

void ScriptingEngine::InitMono(Ref<ApplicationInfo> info)
{
    LP_CORE_INFO("Starting Scripting engine");

    std::string path_to_mono_libs = getExecutablePath();
    path_to_mono_libs.append("\\Mono\\lib");

    std::string path_to_mono_etc = getExecutablePath();
    path_to_mono_etc.append("\\Mono\\etc");


	mono_set_dirs(path_to_mono_libs.c_str(), path_to_mono_etc.c_str());
	mono_config_parse(nullptr);
    monoDomain = mono_jit_init("LowpDomain");
    if (!monoDomain) {
        LP_CORE_ERROR("Failed to initialize Mono JIT.");
        return;
    }


    std::string path_to_dependencies = info->ResourcesDir;
    path_to_dependencies.append("\\Dependencies");

    std::string path_to_api_assembly = info->ResourcesDir;
    path_to_api_assembly.append("\\LowpEngine.dll");

    std::string path_to_game_assembly = info->ResourcesDir;
    path_to_game_assembly.append("\\game.dll");

    LoadAllAssembliesFromDirectory(path_to_dependencies.c_str());
    LoadAssembly(path_to_api_assembly);
    LoadAssembly(path_to_game_assembly);
}

MonoAssembly* ScriptingEngine::LoadAssembly(std::string assemblyPath)
{
    MonoAssembly* assembly = mono_domain_assembly_open(monoDomain, assemblyPath.c_str());
    if (!assembly) {
        std::string error_txt;
        error_txt.append("Failed to load assembly: ");
        error_txt.append(assemblyPath);
        LP_CORE_ERROR(error_txt.c_str());
        return nullptr;
    }
    loaded_assemblies.push_back(assembly);
    return assembly;
}

void ScriptingEngine::LoadAllAssembliesFromDirectory(std::string directoryPath)
{
    for (const auto& entry : fs::directory_iterator(directoryPath)) {
        if (entry.is_regular_file() && entry.path().extension() == ASSEMBLY_EXTENSION) {
            LoadAssembly(entry.path().string());
        }
    }
}

void ScriptingEngine::ShutdownMono()
{
    if (monoDomain) {
        mono_jit_cleanup(monoDomain);
        monoDomain = nullptr;
    }
}
