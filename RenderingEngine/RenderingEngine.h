/* ======================================================================================== */
/* LowpEngine - Rendering Engine C/C++ header file.										    */
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>
#include <GL/glew.h>
#include <SDL2/SDL_vulkan.h>

#include "RendererTypes.h"
#include "FrameworkHandeling/Framework.h"

#include "FrameworkHandeling/Frameworks/OpenGLFramework.h"
#include "FrameworkHandeling/Frameworks/Directx12Framework.h"
#include "FrameworkHandeling/Frameworks/VulkanFramework.h"
#include "FrameworkHandeling/Frameworks/MetalFramework.h"