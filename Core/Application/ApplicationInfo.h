/* ======================================================================================== */
/* LowpEngine - Core C/C++ header file.														*/
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>
#include <Core/Windowing/WindowCreateInfo.h>
#include <Core/Windowing/Resolution.h>

class ApplicationInfo
{
public:
	std::string name, ResourcesDir;
	Ref<Resolution> resolution;
	int flags, renderer_type, audio_system_type;
	Ref<WindowCreateInfo> GetWindowCreateInfo();
	static Ref<ApplicationInfo> GetDefault();
};
