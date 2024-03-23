#include "pch.h"
#include "SoundEngine.h"


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
		IFERR(!sound_device, "OpenAL sound system failed device initialize", "")
			std::string t;
		sound_context = (ALCcontext*)alcCreateContext((ALCdevice*)sound_device, nullptr);
		IFERR(!sound_context, "OpenAL sound system failed failed context init", "")
		
		alcMakeContextCurrent((ALCcontext*)sound_context);
	}

	if (sound_system_backend_type == SoundSystemBackendType::Fmod) {
		LP_CORE_INFO("Starting Fmod");
		FMOD::System* system;
		FMOD::System_Create(&system);
		FMOD_RESULT result = system->init(512, FMOD_INIT_NORMAL, nullptr);
		IFERR(result != FMOD_RESULT::FMOD_OK, "Fmod sound system failed initialize", "")
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

		alcMakeContextCurrent(nullptr);
		alcDestroyContext((ALCcontext*)sound_context);
		alcCloseDevice((ALCdevice*)sound_device);
	}

	if (sound_system_backend_type == SoundSystemBackendType::Fmod) {

	}
}
