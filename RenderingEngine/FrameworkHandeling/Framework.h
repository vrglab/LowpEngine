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

LP_Export class Framework
{
public:
	virtual void Init() = 0;
	virtual void Tick() = 0;
	virtual void SwapWindow(SDL_Window*) = 0;
	virtual void Cleanup() = 0;
};