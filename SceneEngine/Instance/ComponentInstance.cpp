#include "pch.h"
#include "ComponentInstance.h"
#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>
#include <mono/metadata/mono-config.h>
#include <mono/metadata/debug-helpers.h>
#include <Core/Debugging/Debug.h>

void ComponentInstance::Update()
{
    std::string start_method_find_string;
    start_method_find_string.append(base.engine_id.append(":Update()"));

    MonoMethodDesc* methodDesc = mono_method_desc_new(start_method_find_string.c_str(), 0);
    MonoMethod* method = mono_class_get_method_from_name(class_type, "Update", 0);

    mono_method_desc_free(methodDesc);

    if (method) {

        MonoObject* exception = nullptr;
        mono_runtime_invoke(method, created_instance, {}, &exception);

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
