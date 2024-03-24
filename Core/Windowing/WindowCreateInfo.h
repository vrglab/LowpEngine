/* ======================================================================================== */
/* LowpEngine - Core C/C++ header file.														*/
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* The Debug class's implementation is based on the Log class from Hazel by Cherno          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>
#include "Resolution.h"

/**
 * @brief Class holding the window's initial configuration data
 */
struct WindowCreateInfo
{
public:
	std::string window_title;
	Ref<Resolution> resolution;
	int tags, renderer_type;
};