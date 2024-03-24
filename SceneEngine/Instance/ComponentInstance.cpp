#include "pch.h"
#include "ComponentInstance.h"
#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>
#include <mono/metadata/mono-config.h>
#include <mono/metadata/debug-helpers.h>
#include <ScriptingEngine/ScriptingUtils.h>

void ComponentInstance::Update()
{
    ScriptingUtils::InvokeMethod(ScriptingUtils::GetMethod("Update", class_type), created_instance);
}
