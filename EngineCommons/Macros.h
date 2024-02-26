/* ======================================================================================== */
/* LowpEngine - Engine Commons C/C++ header file.											*/
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */

//LP_API
#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#ifdef LP_API_EXPORTS
#define LP_API __declspec(dllexport)
#else
#define LP_API __declspec(dllimport)
#endif
#else
#if __GNUC__ >= 4
#define LP_API __attribute__ ((visibility("default")))
#else
#define LP_API
#endif
#endif


//LP_EXTERN
#define LP_Extern extern "C"

//Debugs
#ifdef DEBUG
#ifdef _WIN32
#define LP_BREAK() __debugbreak()
#elif defined(LP_PLATFORM_LINUX)
#include <signal.h>
#define LP_BREAK() raise(SIGTRAP)
#else
#error "Platform doesn't support debugbreak yet!"
#endif
#define LP_ENABLE_ASSERTS
#else
#define LP_BREAK()
#endif

#define BIT(x) (1 << x)

#if _WIN32
#define ASSEMBLY_EXTENSION ".dll"
#elif defined(__linux__)
#define ASSEMBLY_EXTENSION ".so"
#elif defined(__APPLE__)
#define ASSEMBLY_EXTENSION ".dylib"
#endif