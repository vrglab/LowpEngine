/* ======================================================================================== */
/* LowpEngine - Rendering Engine C/C++ header file.										    */
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>
#include <SDL2/SDL.h>
#include <Core/Application/ApplicationInfo.h>

LP_Export class Framework
{
protected:
	SDL_Window* window_access;
public:
	virtual void OnSdlSetup() = 0;
	virtual void Init(Ref<ApplicationInfo>, SDL_Window*) = 0;
	virtual void Tick() = 0;
	virtual void SwapWindow() = 0;
	virtual void Cleanup() = 0;
};