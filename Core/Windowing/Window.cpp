#include "pch.h"
#include "Window.h"
#include "Application/Application.h"

int Window::Init(Ref<WindowCreateInfo> createInfo)
{
	create_info = createInfo;

	set_win_type_sdl_tag(RendererTypes::OpenGL, SDL_WINDOW_OPENGL)
	set_win_type_sdl_tag(RendererTypes::Vulkan, SDL_WINDOW_VULKAN)
	set_win_type_sdl_tag(RendererTypes::Metal, SDL_WINDOW_METAL)

	IFERRRET(SDL_Init(SDL_INIT_VIDEO) != 0, "Sdl init failed with error: ", SDL_GetError(), LowpResultCodes::SystemFailure)
	sdl_window = SDL_CreateWindow(create_info->window_title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, create_info->resolution->width, create_info->resolution->height, create_info->tags | SDL_WINDOW_HIDDEN);
	IFERRRET(!sdl_window, "Sdl window creation failed with error: ", SDL_GetError(), LowpResultCodes::SystemFailure)

	SDL_GLContext gl_context = {};
	if (create_info->renderer_type == RendererTypes::OpenGL) {
		LP_CORE_INFO("Creating OpenGL Context");
		gl_context = SDL_GL_CreateContext(sdl_window);
		SDL_GL_MakeCurrent(sdl_window, gl_context);
	}
#ifdef EDITOR
	ImGUI::Init(create_info, sdl_window, gl_context);
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
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();
#endif
	SDL_DestroyWindow(sdl_window);
	SDL_Quit();
	return LowpResultCodes::Success;
}
