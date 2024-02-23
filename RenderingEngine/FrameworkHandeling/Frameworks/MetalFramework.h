/* ======================================================================================== */
/* LowpEngine - Rendering Engine C/C++ header file.										    */
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>
#include <Core/Debugging/Debug.h>
#include <Core/Application/ApplicationInfo.h>

#include "RenderingEngine/FrameworkHandeling/Framework.h"

#include <SDL2/SDL_metal.h>

class MetalFramework : Framework
{
private:
#ifdef __APPLE__
	id<MTLDevice> device;
	id<MTLCommandQueue> commandQueue
#endif
public:
	void Init(Ref<ApplicationInfo>, SDL_Window*) override;
	void Tick() override;
#ifdef EDITOR
	void CleanWindow() override;
#endif
	void SwapWindow() override;
	void Cleanup() override;
	void OnSdlSetup() override;
};

