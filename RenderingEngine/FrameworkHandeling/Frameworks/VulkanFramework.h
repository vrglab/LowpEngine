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

#include <vulkan/vulkan.h>

#include <SDL2/SDL_vulkan.h>


class VulkanFramework : Framework
{
private:
	VkInstance instance;

public:
	void Init(Ref<ApplicationInfo>, SDL_Window*) override;
	void Tick() override;
	void SwapWindow() override;
	void Cleanup() override;
};

