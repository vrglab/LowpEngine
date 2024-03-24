#include "pch.h"
#include "GameScripting.h"

#include <ScriptingEngine/ScriptingUtils.h>

MonoImage* game_image;
MonoImage* api_image;
MonoAssembly* api_assembly;
MonoAssembly* game_assembly;
MonoDomain* monoDomain;
std::vector<MonoAssembly*> loaded_assemblies;
ScriptsDatabase database;


void GameScripting::Init(Ref<ApplicationInfo> info)
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


    std::string path_to_dependencies = info->ResourcesDir;
    path_to_dependencies.append("\\Dependencies");

    std::string path_to_api_assembly = info->ResourcesDir;
    path_to_api_assembly.append("\\LowpEngine").append(ASSEMBLY_EXTENSION);

    std::string path_to_game_assembly = info->ResourcesDir;
    path_to_game_assembly.append("\\CoreAssembly").append(ASSEMBLY_EXTENSION);

    ScriptingUtils::LoadAllAssembliesFromDirectory(path_to_dependencies.c_str(), monoDomain, loaded_assemblies);
    api_assembly = ScriptingUtils::LoadAssembly(path_to_api_assembly, monoDomain, loaded_assemblies);
    game_assembly = ScriptingUtils::LoadAssembly(path_to_game_assembly, monoDomain, loaded_assemblies);
    api_image = mono_assembly_get_image(api_assembly);
    game_image = mono_assembly_get_image(game_assembly);
}

MonoObject* GameScripting::CreateComponentClass(Component component, MonoObject* parent_game_obj)
{
    MonoClass* klass = GameScripting::GetClass(component.engine_id);
    MonoObject* obj = mono_object_new(monoDomain, klass);
    mono_runtime_object_init(obj);

    MonoClassField* field = mono_class_get_field_from_name(mono_class_from_name(api_image, "LowpEngine", "LowpBehaviour"), "_gameobj");
    IFNERR(field, mono_field_set_value(obj, field, parent_game_obj); , "_gameobj", " Field not found");

    ScriptingUtils::InvokeMethod(ScriptingUtils::GetMethod("Start", klass), obj);
    return obj;
}

MonoObject* GameScripting::CreateGameObjectClass(GameObjectInstance* gameobj)
{
    MonoClass* klass = mono_class_from_name(api_image, "LowpEngine", "GameObject");

    void* args[1];
    intptr_t myIntPtrValue = reinterpret_cast<uintptr_t>(gameobj);
    args[0] = &myIntPtrValue;

    MonoObject* obj = mono_object_new(monoDomain, klass);
    mono_runtime_object_init(obj);

    MonoClassField* field = mono_class_get_field_from_name(klass, "instance_pointer");
    IFNERR(field, mono_field_set_value(obj, field, &myIntPtrValue); , "_gameobj", " Field not found");

    return obj;
}

MonoClass* GameScripting::GetGameLoadedClassType(std::string id)
{
    MonoClass* klass = database.GetLoadedScript(id);
    if (!klass) {
        MonoClass* baseClass = mono_class_from_name(api_image, "LowpEngine", "LowpBehaviour");
#ifdef GAME
        mono_find_on_rows(game_image, baseClass,         
                LoadedScript ls = {};
                ls.engine_id = name;
                ls.loaded_class_type = klasss;
                database.scripts.push_back(ls); 
                return klasss; ,
                    && name == id
                    )
#endif
#ifdef EDITOR
            return nullptr;
#endif 
    }
    return klass;
}

MonoClass* GameScripting::GetApiLoadedClassType(std::string id)
{
    MonoClass* klass = database.GetLoadedScript(id);
    if (!klass) {
        MonoClass* baseClass = mono_class_from_name(api_image, "LowpEngine", "LowpBehaviour");

#ifdef GAME
        mono_find_on_rows(api_image, baseClass,
            LoadedScript ls = {};
            ls.engine_id = name;
            ls.loaded_class_type = klasss;
            database.scripts.push_back(ls);
            return klasss; ,
            && name == id
            )
#endif
#ifdef EDITOR
            return nullptr;
#endif
    }
    return klass;
}

MonoClass* GameScripting::GetClass(std::string id)
{
    MonoClass* klass = GameScripting::GetGameLoadedClassType(id);
    if (!klass) {
        klass = GameScripting::GetApiLoadedClassType(id);
    }
    return klass;
}

void GameScripting::ShutdownMono()
{
    if (monoDomain) {
        mono_jit_cleanup(monoDomain);
        monoDomain = nullptr;
    }
}