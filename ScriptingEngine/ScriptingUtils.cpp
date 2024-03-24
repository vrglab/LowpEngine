#include "pch.h"
#include "ScriptingUtils.h"
#include <filesystem>

namespace fs = std::filesystem;


MonoClass* ScriptingUtils::GetClass(std::string class_name, MonoImage* image)
{
    std::vector<std::string> split_txt = splitString(class_name, '.');
    return mono_class_from_name(image, joinExceptLast(class_name, '.').c_str(), split_txt[split_txt.size()-1].c_str());
}

MonoMethod* ScriptingUtils::GetMethod(std::string mt_name, MonoClass* klass)
{
    std::string start_method_find_string;
    start_method_find_string.append(mono_class_get_name(klass)).append(":").append(mt_name).append("()");

    MonoMethodDesc* methodDesc = mono_method_desc_new(start_method_find_string.c_str(), FALSE);
    MonoMethod* method = mono_class_get_method_from_name(klass, mt_name.c_str(), 0);

    mono_method_desc_free(methodDesc);
    return method;
}

void ScriptingUtils::InvokeMethod(MonoMethod* method, MonoObject* instance)
{
    if (method && instance) {

        MonoObject* exception = nullptr;
        mono_runtime_invoke(method, instance, {}, &exception);

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

MonoAssembly* ScriptingUtils::LoadAssembly(std::string assemblyPath, MonoDomain* domain, std::vector<MonoAssembly*> loaded_assemblies)
{
    MonoAssembly* assembly = mono_domain_assembly_open(domain, assemblyPath.c_str());
    IFERRRET(!assembly, "Failed to load assembly: ", assemblyPath, nullptr);
    loaded_assemblies.push_back(assembly);
    return assembly;
}

void ScriptingUtils::LoadAllAssembliesFromDirectory(std::string directoryPath, MonoDomain* domain, std::vector<MonoAssembly*> loaded_assemblies)
{
    for (const auto& entry : fs::directory_iterator(directoryPath)) {
        if (entry.is_regular_file() && entry.path().extension() == ASSEMBLY_EXTENSION) {
            LoadAssembly(entry.path().string(), domain, loaded_assemblies);
        }
    }
}

bool ScriptingUtils::IsSubclassOf(MonoClass* test_class, MonoClass* parent)
{
    while (test_class) {
        if (test_class == parent) return true;
        test_class = mono_class_get_parent(test_class);
    }
    return false;
}
