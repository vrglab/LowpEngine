#include "pch.h"
#include <Core/Debugging/Debug.h>
#undef main

#ifdef _WIN32
#include <Windows.h>
int WINAPI main(int argc, char* argv[]) {
    LP_CORE_INFO("Testing tool");
    return 0;
}

#elif defined(__linux__) || defined(__APPLE__)
int main(int argc, char* argv[]) {
    return 0;
}
#else
#error "Unsupported platform"
#endif