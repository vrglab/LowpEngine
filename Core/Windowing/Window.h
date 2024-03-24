/* ======================================================================================== */
/* LowpEngine - Core C/C++ header file.														*/
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>
#include <RenderingEngine/RendererTypes.h>
#include <EventEngine/EventHandler.h>
#include <EventEngine/EventBus.h>
#include <SDL2/SDL.h>
#include <ImGui/ImGui_impl.h>
#include "WindowCreateInfo.h"

/**
 * Engine representation of the OS's window
 */
class Window
{
private:
	SDL_Window* sdl_window;
	Ref<WindowCreateInfo> create_info;
	bool quit = false;

public:
	/**
	 * @return A pointer pointing to the initialized SDL2 window
	 */
	inline SDL_Window* getSdlWindow() { return sdl_window; }

	/**
	 * @brief Initializes the window for the OS
	 * @param createInfo The starting configuration
	 * @return A LowpResultCodes of success upon success
	 */
	int Init(Ref<WindowCreateInfo> createInfo);

	/**
	 * @brief If the window is hidden, it shows the window
	 */
	void ShowWindow();

	/**
	 * @brief if the window is not hidden, it hides the window 
	 */
	void HideWindow();

	/**
	 * @brief Process's all of the qued SDL2 events 
	 */
	void ProcessEvents();

	/**
	 * @return True if the user request for the window to be closed
	 */
	bool ShouldClose();

	/**
	 * @brief Requests for the window to be closed
	 */
	void CloseWindow();

	/**
	 * @brief Cleans the memory from the window
	 * @return A LowpResultCodes of success upon success
	 */
	int CleanUp();
};

#define set_win_type_sdl_tag(x, y) if (create_info->renderer_type == x) { \
create_info->tags |= y; \
}
