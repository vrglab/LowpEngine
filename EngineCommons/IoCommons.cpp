#include "pch.h"
#include "IoCommons.h"


LP_Export char* read_bytes(const std::string& filepath, uint32_t* outSize)
{

    std::ifstream stream(filepath, std::ios::binary | std::ios::ate);

    if (!stream)
    {
        // Failed to open the file
        return nullptr;
    }

    std::streampos end = stream.tellg();
    stream.seekg(0, std::ios::beg);
    uint32_t size = end - stream.tellg();

    if (size == 0)
    {
        // File is empty
        return nullptr;
    }

    char* buffer = new char[size];
    stream.read((char*)buffer, size);
    stream.close();

    *outSize = size;
    return buffer;
}



#include <string>

#ifdef _WIN32
#include <windows.h>
LP_Export std::string getExecutablePath()
{
    char path[MAX_PATH];
    GetModuleFileNameA(NULL, path, MAX_PATH);
    std::string pathStr = path;

    // Remove the executable name
    size_t pos = pathStr.find_last_of("\\/");
    return (std::string::npos == pos) ? "" : pathStr.substr(0, pos);
}

#elif defined(__linux__)
#include <unistd.h>
#include <limits.h>

LP_Export std::string getExecutablePath() {
    char path[PATH_MAX];
    ssize_t count = readlink("/proc/self/exe", path, PATH_MAX);
    std::string pathStr = std::string(path, (count > 0) ? count : 0);

    // Remove the executable name
    size_t pos = pathStr.find_last_of("/");
    return (std::string::npos == pos) ? "" : pathStr.substr(0, pos);
}
#elif defined(__APPLE__)
#include <mach-o/dyld.h>
#include <limits.h>


LP_Export std::string getExecutablePath() {
    char path[PATH_MAX];
    uint32_t size = sizeof(path);
    if (_NSGetExecutablePath(path, &size) != 0) {
        // Buffer size is too small.
        return "";
    }

    // Remove the executable name
    std::string pathStr = path;
    size_t pos = pathStr.find_last_of("/");
    return (std::string::npos == pos) ? "" : pathStr.substr(0, pos);
}
#endif