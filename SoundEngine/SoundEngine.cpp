#include "pch.h"
#include "SoundEngine.h"

#include <Core/Debugging/Debug.h>

void* sound_device;
void* sound_context;
int sound_system_backend_type;

void SoundEngine::Init(Ref<ApplicationInfo> info)
{
	LP_CORE_INFO("Starting Sound Engine");
	sound_system_backend_type = info->audio_system_type;
	if (sound_system_backend_type == SoundSystemBackendType::OpenAL) {
		sound_device = (ALCdevice*)alcOpenDevice(nullptr);
		if (!sound_device) {
			LP_CORE_ERROR("OpenAL soundsystem failed device init");
		}

		sound_context = (ALCcontext*)alcCreateContext((ALCdevice*)sound_device, nullptr);
		if (!sound_context) {
			LP_CORE_ERROR("OpenAL soundsystem failed device init");
		}
		alcMakeContextCurrent((ALCcontext*)sound_context);
	}
}
