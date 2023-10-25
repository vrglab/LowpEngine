#include "pch.h"
#include "Window.h"

int Window::Init(Ref<WindowCreateInfo> createInfo)
{
	WindowCreateInfo* loaded_create_info = createInfo.get();
	create_info = createInfo;

	if (loaded_create_info->renderer_type == RendererTypes::OpenGL) {
		loaded_create_info->tags |= SDL_WINDOW_OPENGL;
	}

	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		LP_CORE_ERROR(SDL_GetError());
		return LowpResultCodes::SystemFailure;
	}

	sdl_window = SDL_CreateWindow(loaded_create_info->window_title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, loaded_create_info->resolution.get()->width, loaded_create_info->resolution.get()->height, loaded_create_info->tags | SDL_WINDOW_HIDDEN);
	if (sdl_window == nullptr) {

		LP_CORE_ERROR(SDL_GetError());
		return LowpResultCodes::SystemFailure;
	}

	return LowpResultCodes::Success;
}

void Window::ShowWindow()
{
	SDL_ShowWindow(sdl_window);
}

void Window::ProcessEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
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
	SDL_DestroyWindow(sdl_window);
	SDL_Quit();
	return LowpResultCodes::Success;
}
