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

	if (create_info->renderer_type == RendererTypes::OpenGL) {
		LP_CORE_INFO("Creating OpenGL Context");
		SDL_GL_MakeCurrent(sdl_window, SDL_GL_CreateContext(sdl_window));
	}

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
		if (event.type == SDL_QUIT) {
			CloseWindow();
		}
		if(event.type == SDL_WINDOWEVENT_RESIZED)
		{
			Application::GetEvenBuss()->QueHandler(window_resize_event);
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
