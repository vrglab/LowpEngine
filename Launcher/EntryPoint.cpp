#include "pch.h"
#include <iostream>
#include <Core/LowpEngine.h>

#undef main

#ifdef _WIN32
// Windows-specific headers and entry point
#include <Windows.h>

int WINAPI main(int argc, char* argv[]) {
    Ref<WindowCreateInfo> create_info = CreateRef<WindowCreateInfo>();
    create_info.get()->renderer_type = RendererTypes::OpenGL;
    create_info.get()->window_title = "Lowp Windows";

    create_info.get()->resolution = CreateRef<Resolution>();
    create_info.get()->resolution.get()->height = 400;
    create_info.get()->resolution.get()->width = 600;

    Window* window = new Window();
    window->Init(create_info);
    window->ShowWindow();
    while (!window->ShouldClose()) 
    {
        window->ProcessEvents();
    }
    window->CleanUp();
    return 0;
}

#elif defined(__linux__) || defined(__unix__) || defined(__APPLE__)
int main(int argc, char* argv[]) {
    
    return 0;
}

#else
#error "Unsupported platform"
#endif