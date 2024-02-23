#include "pch.h"

#include "ImGui_impl.h"

#include <RenderingEngine/RendererTypes.h>
#include <RenderingEngine/FrameworkHandeling/Framework.h>
#include <RenderingEngine/FrameworkHandeling/Frameworks/Directx12Framework.h>

#include "RenderingEngine/FrameworkHandeling/Frameworks/VulkanFramework.h"
#include <imgui_internal.h>

void ImGUI::Init(Ref<WindowCreateInfo> info, SDL_Window* _sdl_window, SDL_GLContext gl_context)
{
	sdl_window = _sdl_window;
	std::string txt = "starting ImGui version ";
	txt.append(IMGUI_VERSION);
	LP_CORE_INFO(txt.c_str());

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable | ImGuiConfigFlags_ViewportsEnable;
	
	ImGui::StyleColorsDark();

	if (info->renderer_type == RendererTypes::OpenGL) {
		ImGui_ImplSDL2_InitForOpenGL(sdl_window, gl_context);
		ImGui_ImplOpenGL3_Init("#version 130");
	}

	if (info->renderer_type == RendererTypes::DirectX12) {
		ImGui_ImplSDL2_InitForD3D(sdl_window);
	}
}

void ImGUI::Tick(Ref<ApplicationInfo> app_info, void* rendering_framework)
{
#ifdef EDITOR
	if (app_info->renderer_type == RendererTypes::OpenGL) {
		ImGui_ImplOpenGL3_NewFrame();
	}
	if (app_info->renderer_type == RendererTypes::Vulkan) {
		ImGui_ImplVulkan_NewFrame();
	}
#ifdef _WIN32
	if (app_info->renderer_type == RendererTypes::DirectX12) {
		ImGui_ImplDX12_NewFrame();
	}
#endif
#ifdef __APPLE__
	if (app_info->renderer_type == RendererTypes::Metal) {
		ImGui_ImplMetal_NewFrame();
	}
#endif


	ImGui_ImplSDL2_NewFrame();
	ImGui::NewFrame();

	if (ImGui::BeginMainMenuBar())
	{
		if (ImGui::BeginMenu("File"))
		{
			ImGui::MenuItem("Open", NULL, false, true);
			ImGui::MenuItem("Save", NULL, false, true);
			ImGui::MenuItem("Exit", NULL, false, true);
			ImGui::EndMenu();
		}

		if (ImGui::BeginMenu("Edit"))
		{
			ImGui::MenuItem("Undo", NULL, false, true);
			ImGui::MenuItem("Redo", NULL, false, true);
			ImGui::MenuItem("Copy", NULL, false, true);
			ImGui::MenuItem("Paste", NULL, false, true);
			ImGui::EndMenu();
		}
		ImGui::EndMainMenuBar();
	}

	dockspace_id = ImGui::GetID("EditorSpace");

	((Framework*)rendering_framework)->Tick();

	ImGui::DockSpace(dockspace_id);

	ImGui::Render();

	((Framework*)rendering_framework)->CleanWindow();


	if (app_info->renderer_type == RendererTypes::OpenGL) {
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		SDL_GLContext context = SDL_GL_GetCurrentContext();
		ImGui::UpdatePlatformWindows();
		ImGui::RenderPlatformWindowsDefault();
		SDL_GL_MakeCurrent(sdl_window, context);
	}

	if (app_info->renderer_type == RendererTypes::Vulkan) {
		ImGui_ImplVulkan_RenderDrawData(ImGui::GetDrawData(), ((VulkanFramework*)rendering_framework)->c_buffer);
		ImGui::UpdatePlatformWindows();
		ImGui::RenderPlatformWindowsDefault();
	}

#ifdef _WIN32
	if (app_info->renderer_type == RendererTypes::DirectX12) {
		ImGui_ImplDX12_RenderDrawData(ImGui::GetDrawData(), ((Directx12Framework*)rendering_framework)->commandList);
		ImGui::UpdatePlatformWindows();
		ImGui::RenderPlatformWindowsDefault();
	}
#endif
#endif
}
