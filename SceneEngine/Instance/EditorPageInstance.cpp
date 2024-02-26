#include "pch.h"
#include "EditorPageInstance.h"
#include <ScriptingEngine/ScriptingUtils.h>

#include "ImGui/ImGui_impl.h"

void EditorPageInstance::Render()
{
	ImGui::Begin(page_type.page_id.c_str(), 0, 0);
    ScriptingUtils::InvokeMethod(ScriptingUtils::GetMethod("ImGuiRender", page_type.loaded_class_type), instance);
	ImGui::End();
}
