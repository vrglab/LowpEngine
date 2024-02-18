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
    api_assembly = LoadAssembly(path_to_api_assembly);
    game_assembly = LoadAssembly(path_to_game_assembly);
    api_image = mono_assembly_get_image(api_assembly);
    game_image = mono_assembly_get_image(game_assembly);
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

MonoObject* ScriptingEngine::CreateComponentClass(Component component, MonoObject* parent_game_obj)
{
    MonoClass* klass = GetGameLoadedClassType(component.engine_id);
    if (!klass) {
        klass = GetApiLoadedClassType(component.engine_id);
    }
    MonoObject* obj = mono_object_new(monoDomain, klass);
    mono_runtime_object_init(obj);

    MonoClass* parentClass = mono_class_from_name(api_image, "LowpEngine", "LowpBehaviour");

    MonoClassField* field = mono_class_get_field_from_name(parentClass, "_gameobj");
    mono_field_set_value(obj, field, parent_game_obj);

    std::string start_method_find_string;
    start_method_find_string.append(mono_class_get_name(klass)).append(":Start()");

    MonoMethodDesc* methodDesc = mono_method_desc_new(start_method_find_string.c_str(), FALSE);
    MonoMethod* method = mono_class_get_method_from_name(klass, "Start", 0);

    mono_method_desc_free(methodDesc);

        if (method) {

            MonoObject* exception = nullptr;
            mono_runtime_invoke(method, obj, {}, &exception);

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

MonoObject* ScriptingEngine::CreateGameObjectClass(GameObjectInstance* instance)
{
    MonoClass* klass = mono_class_from_name(api_image, "LowpEngine", "GameObject");

    void* args[1];
    intptr_t myIntPtrValue = reinterpret_cast<uintptr_t>(instance);
    args[0] = &myIntPtrValue;

    MonoObject* obj = mono_object_new(monoDomain, klass);
    mono_runtime_object_init(obj);

    MonoClassField* field = mono_class_get_field_from_name(klass, "instance_pointer");
    if (field) {
        mono_field_set_value(obj, field, &myIntPtrValue);
    }
    else {
        // Handle the error: Field not found
    }

    return obj;
}

MonoClass* ScriptingEngine::GetGameLoadedClassType(std::string id)
{
    MonoClass* klass = database.GetLoadedScript(id);
    if (!klass) {
        MonoClass* baseClass = mono_class_from_name(api_image, "LowpEngine", "LowpBehaviour");

        const MonoTableInfo* typeTable = mono_image_get_table_info(game_image, MONO_TABLE_TYPEDEF);
        int rows = mono_table_info_get_rows(typeTable);
        for (int i = 1; i <= rows; i++) {
            uint32_t cols[MONO_TYPEDEF_SIZE];
            mono_metadata_decode_row(typeTable, i - 1, cols, MONO_TYPEDEF_SIZE);
            const char* name = mono_metadata_string_heap(game_image, cols[MONO_TYPEDEF_NAME]);
            const char* nameSpace = mono_metadata_string_heap(game_image, cols[MONO_TYPEDEF_NAMESPACE]);
            MonoClass* klasss = mono_class_from_name(game_image, nameSpace, name);

            if (IsSubclassOf(klasss, baseClass) && name == id) {
                LoadedScript ls = {};
                ls.engine_id = name;
                ls.loaded_class_type = klasss;
                database.scripts.push_back(ls);
                return klasss;
            }
        }
    }
    return klass;
}

MonoClass* ScriptingEngine::GetApiLoadedClassType(std::string id)
{
    MonoClass* klass = database.GetLoadedScript(id);
    if (!klass) {
        MonoClass* baseClass = mono_class_from_name(api_image, "LowpEngine", "LowpBehaviour");

        const MonoTableInfo* typeTable = mono_image_get_table_info(api_image, MONO_TABLE_TYPEDEF);
        int rows = mono_table_info_get_rows(typeTable);
        for (int i = 1; i <= rows; i++) {
            uint32_t cols[MONO_TYPEDEF_SIZE];
            mono_metadata_decode_row(typeTable, i - 1, cols, MONO_TYPEDEF_SIZE);
            const char* name = mono_metadata_string_heap(api_image, cols[MONO_TYPEDEF_NAME]);
            const char* nameSpace = mono_metadata_string_heap(api_image, cols[MONO_TYPEDEF_NAMESPACE]);
            MonoClass* klasss = mono_class_from_name(api_image, nameSpace, name);

            if (IsSubclassOf(klasss, baseClass) && name == id) {
                LoadedScript ls = {};
                ls.engine_id = name;
                ls.loaded_class_type = klasss;
                database.scripts.push_back(ls);
                return klasss;
            }
        }
    }
    return klass;
}

bool ScriptingEngine::IsSubclassOf(MonoClass* child, MonoClass* parent) {
    while (child) {
        if (child == parent) return true;
        child = mono_class_get_parent(child);
    }
    return false;
}