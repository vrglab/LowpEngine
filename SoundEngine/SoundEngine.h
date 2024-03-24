/* ======================================================================================== */
/* LowpEngine - Sound Engine C/C++ header file.												*/
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>
#include <Core/Application/ApplicationInfo.h>
#include <AL/al.h>
#include <AL/alc.h>
#include <fmod_common.h>
#include <fmod.hpp>
#include <fmod_errors.h>

LP_Extern LP_API int sound_system_backend_type;
LP_Extern LP_API void* sound_device;
LP_Extern LP_API void* sound_context;


#include "SoundSystemType.h"

class SoundEngine {
private:
	static inline std::vector<void*> created_buffers;
	static inline std::vector<void*> created_sources;
public:

	/**
	 * @brief Starts the Audio engine
	 * @param info The starting configs of the application
	 */
	static void Init(Ref<ApplicationInfo> info);

	/**
	 * @brief Creates a audio source from a audio asset in the asset database
	 * @param hrid The hrid of the audio asset
	 * @return The created audio source
	 */
	static void* CreateSound(std::string hrid);

	/**
	 * @brief shuts down the audio engine and cleans the memory
	 */
	static void Shutdown();
};