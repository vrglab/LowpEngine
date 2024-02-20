#include "pch.h"
#include "Window.h"
#include "Application/Application.h"

int Window::Init(Ref<WindowCreateInfo> createInfo)
{
	create_info = createInfo;

	if (create_info->renderer_type == RendererTypes::OpenGL) {
		create_info->tags |= SDL_WINDOW_OPENGL;
	}
	
	if (create_info->renderer_type == RendererTypes::Vulkan) {
		create_info->tags |= SDL_WINDOW_VULKAN;
	}

	if (create_info->renderer_type == RendererTypes::Metal) {
		create_info->tags |= SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_METAL;
	}

	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		LP_CORE_ERROR(SDL_GetError());
		return LowpResultCodes::SystemFailure;
	}

	sdl_window = SDL_CreateWindow(create_info->window_title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, create_info->resolution->width, create_info->resolution->height, create_info->tags | SDL_WINDOW_HIDDEN);
	if (sdl_window == nullptr) {

		LP_CORE_ERROR(SDL_GetError());
		return LowpResultCodes::SystemFailure;
	}
	SDL_GLContext gl_context = {};
	if (create_info->renderer_type == RendererTypes::OpenGL) {
		LP_CORE_INFO("Creating OpenGL Context");
		gl_context = SDL_GL_CreateContext(sdl_window);
		SDL_GL_MakeCurrent(sdl_window, gl_context);
	}
#ifdef EDITOR
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;

	// Setup ImGui style
	ImGui::StyleColorsDark();


	if (create_info->renderer_type == RendererTypes::OpenGL) {
		ImGui_ImplSDL2_InitForOpenGL(sdl_window, gl_context);
		ImGui_ImplOpenGL3_Init("#version 130");
	}
#endif

	return LowpResultCodes::Success;
}

void Window::ShowWindow()
{
	SDL_ShowWindow(sdl_window);
}

void Window::HideWindow()
{
	SDL_HideWindow(sdl_window);
}

void Window::ProcessEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
#ifdef EDITOR
		ImGui_ImplSDL2_ProcessEvent(&event);
#endif
		if (event.type == SDL_QUIT) {
			CloseWindow();
		}
	}
}

bool Window::ShouldClose()
{
	return quit;
}

void Window::CloseWindow()
{
	quit = true;
}

int Window::CleanUp()
{
#ifdef EDITOR
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();
#endif
	SDL_DestroyWindow(sdl_window);
	SDL_Quit();
	return LowpResultCodes::Success;
}
