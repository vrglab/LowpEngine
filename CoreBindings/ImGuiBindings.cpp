#include "pch.h"
#include "ImGuiBindings.h"

LP_Extern LP_BINDINGS_API void imgui_text(char* txt)
{
    ImGui::Text(txt);
}
