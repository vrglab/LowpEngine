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
	static void Init(Ref<ApplicationInfo>);
	static void* CreateSound(std::string hrid);
	static void Shutdown();
};