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

/**
 * @brief Class holding the application's initial configuration data
 */
class ApplicationInfo
{
public:
	std::string name, ResourcesDir;
	Ref<Resolution> resolution;
	int flags, renderer_type, audio_system_type;

	/**
	 * Generates a optimal window creation config based on it's own configuration's
	 * @return Smart pointer pointing to the created WindowCreateInfo
	 */
	LP_API Ref<WindowCreateInfo> GetWindowCreateInfo();

	/**
	 * Generates a default ApplicationInfo configuration for the OS
	 * @return The created configs 
	 */
	LP_API static Ref<ApplicationInfo> GetDefault();
};
