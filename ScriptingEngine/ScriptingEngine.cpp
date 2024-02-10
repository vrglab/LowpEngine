#include "pch.h"
#include "ScriptingEngine.h"
#include <Core/Debugging/Debug.h>
#include <mono/metadata/debug-helpers.h>

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
    path_to_api_assembly.append("\\LowpEngine").append(ASSEMBLY_EXTENSION);

    std::string path_to_game_assembly = info->ResourcesDir;
    path_to_game_assembly.append("\\CoreAssembly").append(ASSEMBLY_EXTENSION);

    LoadAllAssembliesFromDirectory(path_to_dependencies.c_str());
    MonoAssembly* api_assembly = LoadAssembly(path_to_api_assembly);
    LoadAssembly(path_to_game_assembly);
    api_image = mono_assembly_get_image(api_assembly);


    /***** TEST CODE BEGINS HERE *****/

    MonoClass* klass = mono_class_from_name(api_image, "LowpEngine", "Debug");
    if (!klass) {
        // Handle error
    }

    MonoMethodDesc* methodDesc = mono_method_desc_new("Debug:LogWarning(System.String)", FALSE);
    MonoMethod* method = mono_class_get_method_from_name(klass, "LogWarning", 1);
    
    mono_method_desc_free(methodDesc);

    if (!method) {
        // Handle error
    }

    const char* argValue = "Hello world";
    MonoString* monoArg = mono_string_new(monoDomain, argValue);
    void* args[] = { monoArg };

    MonoObject* exception = nullptr;
    MonoObject* result = mono_runtime_invoke(method, nullptr, args, &exception);

    if (exception) {
        MonoMethod* get_message_method = mono_class_get_method_from_name(mono_get_exception_class(), "get_Message", 0);
        MonoObject* message_obj = mono_runtime_invoke(get_message_method, exception, nullptr, nullptr);
        if (message_obj != nullptr) {
            MonoString* message_mono_str = (MonoString*)message_obj;
            char* message = mono_string_to_utf8(message_mono_str);
            LP_CORE_ERROR(message);
            mono_free(message);
        }
    }
    else {

    }
    /***** TEST CODE ENDS HERE *****/
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

MonoObject* ScriptingEngine::CreateComponentClass(Component component)
{
    MonoClass* klass = mono_class_from_name(api_image, component.mono_namespace_name.c_str(), component.mono_class_name.c_str());
    MonoObject* obj = mono_object_new(monoDomain, klass);
    mono_runtime_object_init(obj);

    MonoMethodDesc* methodDesc = mono_method_desc_new(component.mono_class_name.append(":Start()").c_str(), FALSE);
    MonoMethod* method = mono_class_get_method_from_name(klass, "Start", 1);

    mono_method_desc_free(methodDesc);

    if (method) {
        void* args[] = { };

        MonoObject* exception = nullptr;
        mono_runtime_invoke(method, nullptr, args, &exception);

        if (exception) {
            MonoMethod* get_message_method = mono_class_get_method_from_name(mono_get_exception_class(), "get_Message", 0);
            MonoObject* message_obj = mono_runtime_invoke(get_message_method, exception, nullptr, nullptr);
            if (message_obj != nullptr) {
                MonoString* message_mono_str = (MonoString*)message_obj;
                char* message = mono_string_to_utf8(message_mono_str);
                LP_ERROR(message);
                mono_free(message);
            }
        }
        else {

        }
    }
    return obj;
}