#include "pch.h"
#include "EditorScripting.h"

#include <ScriptingEngine/ScriptingUtils.h>

MonoDomain* monoDomain;
std::vector<MonoAssembly*> loaded_assemblies;
ScriptsDatabase database;
MonoAssembly* editor_assembly;
MonoImage* editor_image;

EditorPageType EditorScripting::GetPageType(std::string id)
{
#ifdef EDITOR
    return database.GetLoadedPageType(id);
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
#ifdef EDITOR
        mono_find_on_rows(editor_image, baseClass, 
            EditorPageType ls = {}; 
            ls.page_id = name; 
            ls.loaded_class_type = klasss; 
            database.scripts.push_back(ls); 
            return klasss; , && name == id
                )
#endif
#ifdef GAME
            return nullptr;
#endif
    }
    return klass;
}

MonoObject* EditorScripting::CreatePageInstance(EditorPageType type)
{
    MonoObject* obj = mono_object_new(monoDomain, type.loaded_class_type);
    mono_runtime_object_init(obj);

    ScriptingUtils::InvokeMethod(ScriptingUtils::GetMethod("Start", type.loaded_class_type), obj);
    return obj;
}

std::vector<std::string> EditorScripting::GetPages()
{
    std::vector<std::string> list = {};
    MonoClass* baseClass = mono_class_from_name(editor_image, "LowpEditor", "EditorWindow");

    mono_find_on_rows(editor_image, baseClass, if (name != "EditorWindow") {list.push_back(name);})
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

    ScriptingUtils::LoadAllAssembliesFromDirectory(path_to_dependencies.c_str(), monoDomain, loaded_assemblies);
    editor_assembly = ScriptingUtils::LoadAssembly(path_to_api_assembly, monoDomain, loaded_assemblies);
    editor_image = mono_assembly_get_image(editor_assembly);
}

void EditorScripting::ShutdownMono()
{
    if (monoDomain) {
        mono_jit_cleanup(monoDomain);
        monoDomain = nullptr;
    }
}
