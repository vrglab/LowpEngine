#include "pch.h"
#include "ScriptingEngine.h"
#include <Core/Debugging/Debug.h>

void ScriptingEngine::InitMono()
{
    LP_CORE_INFO("Starting Scripting engine");
	mono_set_dirs("Mono/MonoBleedingEdge", "Mono/configs");
	mono_config_parse(nullptr);
    monoDomain = mono_jit_init("GameEngineDomain");
    if (!monoDomain) {
        LP_CORE_ERROR("Failed to initialize Mono JIT.");
        return;
    }
}

void ScriptingEngine::ShutdownMono()
{
    if (monoDomain) {
        mono_jit_cleanup(monoDomain);
        monoDomain = nullptr;
    }
}
