#include "pch.h"
#include "IoCommons.h"
#include <sstream>
#include <cereal/archives/binary.hpp>

LP_API std::string read_bytes(const std::string& filepath)
{

    std::ifstream stream(filepath, std::ios::binary | std::ios::ate);
    IFERRRET(!stream, "Failed to open file: ", filepath, nullptr)
    std::streampos end = stream.tellg();
    stream.seekg(0, std::ios::beg);
    uint32_t size = end - stream.tellg();
    IFERRRET(size == 0, "Failed to read file", "", nullptr)
    std::vector<char> buffer(size);
    stream.read(buffer.data(), size);
    return std::string(buffer.begin(), buffer.end());
}

std::ofstream GenerateFile(std::string filepath, std::string filename)
{
    std::string path = filepath;
    path.append(filename);
    path.append(".bin");

    std::ofstream  file_stream(path.c_str(), std::ios::binary);
    IFERRTHROW(!file_stream.is_open(), "Failed to open file for writing.");
}

LP_API std::vector<std::string> splitString(const std::string& text, char delim)
{
    std::vector<std::string> tokens;
    std::istringstream iss(text);
    std::string token;

    while (std::getline(iss, token, delim)) 
    {
    	if (!token.empty()) 
        {
            tokens.push_back(token);
        }
    }

    return tokens;
}

LP_API std::string joinExceptLast(const std::string& text, char delim) {
    std::istringstream iss(text);
    std::string token;
    std::string result;
    std::string last;

    while (std::getline(iss, token, delim)) 
    {
        if (!token.empty()) 
        {
            if (!result.empty()) 
            {
                result += delim; 
			}   
            result += last;
            last = token;
		}
    }

    return result;
}

#if defined(_WIN32)
#include <objbase.h>
#elif defined(__linux__) || defined(__APPLE__)
#include <uuid/uuid.h>
#endif
#include <iomanip>

LP_API std::string GUIDGen()
{
    std::stringstream ss;
#if defined(_WIN32)
    GUID guid;
    CoCreateGuid(&guid);
    ss << std::hex
        << std::uppercase
        << std::setfill('0')
        << std::setw(8) << guid.Data1 << '-'
        << std::setw(4) << guid.Data2 << '-'
        << std::setw(4) << guid.Data3 << '-'
        << std::setw(2) << static_cast<short>(guid.Data4[0])
        << std::setw(2) << static_cast<short>(guid.Data4[1]) << '-'
        << std::setw(2) << static_cast<short>(guid.Data4[2])
        << std::setw(2) << static_cast<short>(guid.Data4[3])
        << std::setw(2) << static_cast<short>(guid.Data4[4])
        << std::setw(2) << static_cast<short>(guid.Data4[5])
        << std::setw(2) << static_cast<short>(guid.Data4[6])
        << std::setw(2) << static_cast<short>(guid.Data4[7]);
#elif defined(__linux__) || defined(__APPLE__)
    uuid_t uuid;
    uuid_generate_random(uuid);
    char str[37]; // UUID string length + null terminator
    uuid_unparse_upper(uuid, str);
    ss << str;
#endif

    return ss.str();
}

#include <string>
#ifdef _WIN32
#include <windows.h>
#elif defined(__linux__)
#include <unistd.h>
#include <limits.h>
#elif defined(__APPLE__)
#include <mach-o/dyld.h>
#include <limits.h>
#endif

LP_API std::string getExecutablePath()
{
#ifdef _WIN32
    char path[MAX_PATH];
    GetModuleFileNameA(NULL, path, MAX_PATH);
    std::string pathStr = path;

    // Remove the executable name
    size_t pos = pathStr.find_last_of("\\/");
    return (std::string::npos == pos) ? "" : pathStr.substr(0, pos);
#elif defined(__linux__)
    char path[PATH_MAX];
    ssize_t count = readlink("/proc/self/exe", path, PATH_MAX);
    std::string pathStr = std::string(path, (count > 0) ? count : 0);

    // Remove the executable name
    size_t pos = pathStr.find_last_of("/");
    return (std::string::npos == pos) ? "" : pathStr.substr(0, pos);
#elif defined(__APPLE__)
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
#endif
}