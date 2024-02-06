#include "pch.h"
#include "ScriptingEngine.h"

void ScriptingEngine::InitMono()
{
	mono_set_dirs("Mono/MonoBleedingEdge", "Mono/configs");
	mono_config_parse(nullptr);
    monoDomain = mono_jit_init("GameEngineDomain");
    if (!monoDomain) {
        std::cerr << "Failed to initialize Mono JIT." << std::endl;
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
