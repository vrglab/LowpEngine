#include "pch.h"
#include <iostream>
#include <Core/LowpEngine.h>
#include <ScriptingEngine/ScriptingEngine.h>
#include <SoundEngine/SoundEngine.h>

#undef main

#ifdef _WIN32
#include <Windows.h>
int WINAPI main(int argc, char* argv[]) {

    LP_CORE_INFO("Starting Lowp Editor on version 1.0.0");
    Ref<Application> app = CreateRef<Application>();

    Ref<ApplicationInfo> info = ApplicationInfo::GetDefault();
    info->name = "Lowp Editor";
    info->renderer_type = RendererTypes::OpenGL;

    app->app_info = info;
    app->InitSubEngines();
    app->CreateAppWindow(info->GetWindowCreateInfo());
    app->Run();
    app->CleanUp();
    return 0;
}

#elif defined(__linux__) || defined(__APPLE__)
int main(int argc, char* argv[]) {
    return 0;
}
#else
#error "Unsupported platform"
#endif