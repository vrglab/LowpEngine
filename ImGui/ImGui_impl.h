/* ======================================================================================== */
/* LowpEngine - ImGui C/C++ header file.													*/
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>

#include <Core/Debugging/Debug.h>
#include <Core/Application/ApplicationInfo.h>

#include <SDL2/SDL.h>

#include "imgui.h"
#include "misc/cpp/imgui_stdlib.h"
#include "backends/imgui_impl_sdl2.h"
#include "backends/imgui_impl_opengl3.h"
#include "backends/imgui_impl_vulkan.h"
#ifdef _WIN32
#include "backends/imgui_impl_dx12.h"
#endif
#ifdef __APPLE__
#include "backends/imgui_impl_metal.h"
#endif

class ImGUI
{
private:
	static inline SDL_Window* sdl_window;
public:
	static void Init(Ref<WindowCreateInfo>, SDL_Window* sdl_window, SDL_GLContext gl_context);
	static void Tick(Ref<ApplicationInfo>, void*);
};