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
#include <SDL2/SDL_opengl.h>
#ifdef EDITOR
#include <ImGui/imgui.h>
#include <ImGui/misc/cpp/imgui_stdlib.h>
#include <ImGui/backends/imgui_impl_sdl2.h>
#include <ImGui/backends/imgui_impl_opengl3.h>
#ifdef _WIN32
#include <ImGui/backends/imgui_impl_dx12.h>
#endif
#endif
#include "Debugging/Debug.h"
#include "WindowCreateInfo.h"

class Window
{
private:
	SDL_Window* sdl_window;
	Ref<WindowCreateInfo> create_info;
	bool quit = false;
public:
	inline SDL_Window* getSdlWindow() { return sdl_window; }
	int Init(Ref<WindowCreateInfo> createInfo);
	void ShowWindow();
	void HideWindow();
	void ProcessEvents();
	bool ShouldClose();
	void CloseWindow();
	int CleanUp();
};