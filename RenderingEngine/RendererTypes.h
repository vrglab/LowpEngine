/* ======================================================================================== */
/* LowpEngine - Core C/C++ header file.														*/
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>
#include <vk_video/vulkan_video_codecs_common.h>


LP_Export enum RendererTypes
{
	OpenGL = 0,
	Vulkan = 1,
	DirectX12 = 2,
	Metal = 3
};

LP_Export int getSystemSupportedRenderer();