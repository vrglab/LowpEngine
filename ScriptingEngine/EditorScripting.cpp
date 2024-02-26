#include "pch.h"
#include "EditorScripting.h"


MonoDomain* monoDomain;
std::vector<MonoAssembly*> loaded_assemblies;
ScriptsDatabase database;
MonoAssembly* editor_assembly;
MonoImage* editor_image;

MonoAssembly* EditorScripting::LoadAssembly(std::string assemblyPath)
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

void EditorScripting::LoadAllAssembliesFromDirectory(std::string directoryPath)
{
    for (const auto& entry : fs::directory_iterator(directoryPath)) {
        if (entry.is_regular_file() && entry.path().extension() == ASSEMBLY_EXTENSION) {
            LoadAssembly(entry.path().string());
        }
    }
}

EditorPageType EditorScripting::GetPage_(std::string id)
{
#ifdef EDITOR
    return database.GetLoadedScript_(id);
#endif
#ifdef GAME
    return {};
#endif
}

MonoClass* EditorScripting::GetPage(std::string id)
{
    MonoClass* klass = database.GetLoadedScript(id);
    if (!klass) {
        MonoClass* baseClass = mono_class_from_name(editor_image, "LowpEditor", "EditorWindow");

        const MonoTableInfo* typeTable = mono_image_get_table_info(editor_image, MONO_TABLE_TYPEDEF);
        int rows = mono_table_info_get_rows(typeTable);
        for (int i = 1; i <= rows; i++) {
            uint32_t cols[MONO_TYPEDEF_SIZE];
            mono_metadata_decode_row(typeTable, i - 1, cols, MONO_TYPEDEF_SIZE);
            const char* name = mono_metadata_string_heap(editor_image, cols[MONO_TYPEDEF_NAME]);
            const char* nameSpace = mono_metadata_string_heap(editor_image, cols[MONO_TYPEDEF_NAMESPACE]);
            MonoClass* klasss = mono_class_from_name(editor_image, nameSpace, name);

            if (IsSubclassOf(klasss, baseClass) && name == id) {
#ifdef EDITOR
                EditorPageType ls = {};
                ls.page_id = name;
                ls.loaded_class_type = klasss;
                database.scripts.push_back(ls);
#endif
                return klasss;
            }
        }
    }
    return klass;
}

MonoObject* EditorScripting::CreatePageInstance(EditorPageType page)
{
    MonoObject* obj = mono_object_new(monoDomain, page.loaded_class_type);
    mono_runtime_object_init(obj);

    std::string start_method_find_string;
    start_method_find_string.append(mono_class_get_name(page.loaded_class_type)).append(":Start()");

    MonoMethodDesc* methodDesc = mono_method_desc_new(start_method_find_string.c_str(), FALSE);
    MonoMethod* method = mono_class_get_method_from_name(page.loaded_class_type, "Start", 0);

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
}

std::vector<std::string> EditorScripting::GetPages()
{
    std::vector<std::string> list = {};
    MonoClass* baseClass = mono_class_from_name(editor_image, "LowpEditor", "EditorWindow");

    const MonoTableInfo* typeTable = mono_image_get_table_info(editor_image, MONO_TABLE_TYPEDEF);
    int rows = mono_table_info_get_rows(typeTable);
    for (int i = 1; i <= rows; i++) {
        uint32_t cols[MONO_TYPEDEF_SIZE];
        mono_metadata_decode_row(typeTable, i - 1, cols, MONO_TYPEDEF_SIZE);
        const char* name = mono_metadata_string_heap(editor_image, cols[MONO_TYPEDEF_NAME]);
        const char* nameSpace = mono_metadata_string_heap(editor_image, cols[MONO_TYPEDEF_NAMESPACE]);
        MonoClass* klasss = mono_class_from_name(editor_image, nameSpace, name);

        if (IsSubclassOf(klasss, baseClass)) {
            if (name != "EditorWindow") {
                list.push_back(name);
            }
        }
    }
    return list;
}

void EditorScripting::Init()
{
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

    std::string path_to_dependencies = getExecutablePath();
    path_to_dependencies.append("\\Dependencies");

    std::string path_to_api_assembly = getExecutablePath();
    path_to_api_assembly.append("\\LowpEditor").append(ASSEMBLY_EXTENSION);

    LoadAllAssembliesFromDirectory(path_to_dependencies.c_str());
    editor_assembly = LoadAssembly(path_to_api_assembly);
    editor_image = mono_assembly_get_image(editor_assembly);
}

void EditorScripting::ShutdownMono()
{
    if (monoDomain) {
        mono_jit_cleanup(monoDomain);
        monoDomain = nullptr;
    }
}

bool EditorScripting::IsSubclassOf(MonoClass* child, MonoClass* parent) {
    if (child == parent) return false;
    while (child) {
        if (child == parent) return true;
        child = mono_class_get_parent(child);
    }
    return false;
}