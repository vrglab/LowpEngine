#include "pch.h"
#include <iostream>
#include <Core/LowpEngine.h>
#include "Player.h"

#undef main

#ifdef _WIN32
#include <Windows.h>
int WINAPI main(int argc, char* argv[]) {
    Ref<Application> app = CreateRef<Application>();
    app->Init(Player::LoadAppData());
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