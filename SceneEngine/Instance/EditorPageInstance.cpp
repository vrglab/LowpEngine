#include "pch.h"
#include "EditorPageInstance.h"

#include "ImGui/ImGui_impl.h"

void EditorPageInstance::Render()
{
	ImGui::Begin(page_type.page_id.c_str(), 0, 0);

    std::string start_method_find_string;
    start_method_find_string.append(mono_class_get_name(page_type.loaded_class_type)).append(":ImGuiRender()");

    MonoMethodDesc* methodDesc = mono_method_desc_new(start_method_find_string.c_str(), FALSE);
    MonoMethod* method = mono_class_get_method_from_name(page_type.loaded_class_type, "ImGuiRender", 0);

    mono_method_desc_free(methodDesc);

    if (method) {

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

	ImGui::End();
}
