/* ======================================================================================== */
/* LowpEngine - Rendering Engine C/C++ header file.										    */
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>
#include "RenderingEngine/FrameworkHandeling/Framework.h"
#include <SDL2/SDL.h>

class OpenGLFramework : Framework
{
public:
	void Init() override;
	void Tick() override;
	void SwapWindow(SDL_Window*) override;
	void Cleanup() override;
};