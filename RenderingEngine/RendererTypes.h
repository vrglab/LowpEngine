/* ======================================================================================== */
/* LowpEngine - Rendering Engine C/C++ header file.										    */
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>
#include <vk_video/vulkan_video_codecs_common.h>


LP_API enum RendererTypes
{
	OpenGL = 0,
	Vulkan = 1,
	DirectX12 = 2,
	Metal = 3
};

/**
 * @brief Get's the best possible Renderer type for the current computers OS
 * @return The best render using it's RendererTypes enum number
 */
LP_API int getSystemSupportedRenderer();