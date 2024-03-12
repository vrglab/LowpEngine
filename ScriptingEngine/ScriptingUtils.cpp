#include "pch.h"
#include "ScriptingUtils.h"



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