#include "pch.h"
#include <iostream>

#undef main

#ifdef _WIN32
// Windows-specific headers and entry point
#include <Windows.h>

int WINAPI main(int argc, char* argv[]) {
    
    return 0;
}

#elif defined(__linux__) || defined(__unix__) || defined(__APPLE__)
int main(int argc, char* argv[]) {
    
    return 0;
}

#else
#error "Unsupported platform"
#endif