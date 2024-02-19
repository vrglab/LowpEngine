/* ======================================================================================== */
/* LowpEngine - Engine Commons C/C++ header file.											*/
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */

//LP_API
#ifdef _WIN32
#ifdef LP_API_EXPORTS
#define LP_API __declspec(dllexport)
#else
#define LP_API __declspec(dllimport)
#endif
#else
#ifdef LP_API_EXPORTS
#define LP_API __attribute__((visibility("default")))
#else
#define LP_API __attribute__((visibility("default")))
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
