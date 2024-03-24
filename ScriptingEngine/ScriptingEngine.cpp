#include "pch.h"
#include "ScriptingEngine.h"
#include <mono/metadata/debug-helpers.h>


void ScriptingEngine::InitMono(Ref<ApplicationInfo> info)
{
    LP_CORE_INFO("Starting Scripting engine");
#ifdef GAME
    GameScripting::Init(info);
#endif
#ifdef EDITOR
    EditorScripting::Init();
#endif
}

void ScriptingEngine::ShutdownMono()
{
#ifdef GAME
    GameScripting::ShutdownMono();
#endif
#ifdef EDITOR
    EditorScripting::ShutdownMono();
#endif
}

MonoDomain* ScriptingEngine::GetCurrentDomain()
{
    return monoDomain;
}
