#include "pch.h"
#include <iostream>
#include <Core/LowpEngine.h>

#undef main

#ifdef _WIN32
#include <Windows.h>

void OnWindowResized() {
    LP_CORE_INFO("Window resize event was called");
}

int WINAPI main(int argc, char* argv[]) {
    Ref<ApplicationInfo> create_info = CreateRef<ApplicationInfo>();
    create_info->renderer_type = RendererTypes::OpenGL;
    create_info->name = "Lowp Windows";

    create_info->resolution = CreateRef<Resolution>();
    create_info->resolution->height = 400;
    create_info->resolution->width = 600;

    Application* app = new Application();
    app->Init(create_info);
    app->GetWindow()->window_resize_event->AddListener(OnWindowResized);
    app->Run();
    app->CleanUp();
    return 0;
}

#elif defined(__linux__) || defined(__unix__) || defined(__APPLE__)
int main(int argc, char* argv[]) {
    
    return 0;
}

#else
#error "Unsupported platform"
#endif