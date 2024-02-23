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
		LP_CORE_INFO("Starting OpenAL");
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

	if (sound_system_backend_type == SoundSystemBackendType::Fmod) {
		LP_CORE_INFO("Starting Fmod");
		FMOD::System* system;
		FMOD::System_Create(&system);
		system->init(512, FMOD_INIT_NORMAL, nullptr);
		sound_device = system;
	}
}

void* SoundEngine::CreateSound(std::string hrid)
{
	if (sound_system_backend_type == SoundSystemBackendType::OpenAL) {
		ALuint buffer;
		alGenBuffers(1, &buffer);
		created_buffers.push_back((void*)buffer);

		ALuint source;
		alGenSources(1, &source);
		alSourcei(source, AL_BUFFER, buffer);
		alSourcef(source, AL_PITCH, 1);
		created_sources.push_back((void*)source);
		return (void*)source;
	}

	if (sound_system_backend_type == SoundSystemBackendType::Fmod) {
		
	}
}

void SoundEngine::Shutdown()
{
	if (sound_system_backend_type == SoundSystemBackendType::OpenAL) {
		//TODO: remove sources
		for (size_t i = 0; i < created_sources.size(); i++)
		{
			ALuint buffer = (ALuint)created_sources[i];
			alDeleteSources(1, &buffer);
		}
		
		for (size_t i = 0; i < created_buffers.size(); i++)
		{
			ALuint buffer = (ALuint)created_buffers[i];
			alDeleteBuffers(1, &buffer);
		}
	}

	if (sound_system_backend_type == SoundSystemBackendType::Fmod) {

	}
}
