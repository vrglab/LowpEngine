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
#include <SDL2/SDL.h>
#include "Debugging/Debug.h"
#include "WindowCreateInfo.h"

LP_Export class Window
{
private:
	SDL_Window* sdl_window;
	Ref<WindowCreateInfo> create_info;
	bool quit = false;
public:
	int Init(Ref<WindowCreateInfo> createInfo);
	void ShowWindow();
	void ProcessEvents();
	bool ShouldClose();
	void CloseWindow();
	int CleanUp();
};