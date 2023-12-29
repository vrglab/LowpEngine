#include "pch.h"
#include <iostream>
#include <Core/LowpEngine.h>

#undef main

#ifdef _WIN32
#include <Windows.h>
int WINAPI main(int argc, char* argv[]) {
    Ref<ApplicationInfo> create_info = CreateRef<ApplicationInfo>();
    create_info->renderer_type = getSystemSupportedRenderer();
    create_info->name = "Lowp Windows";

    create_info->resolution = CreateRef<Resolution>();
    create_info->resolution->height = 600;
    create_info->resolution->width = 1000;
    create_info->flags |= SDL_WINDOW_RESIZABLE;

    Ref<Application> app = CreateRef<Application>();
    app->Init(create_info);
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