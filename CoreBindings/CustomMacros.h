/* ======================================================================================== */
/* LowpEngine - CoreBindings C/C++ header file.												*/
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once

#ifdef _WIN32
#ifdef LP_BINDINGS_API_EXPORTS
#define LP_BINDINGS_API __declspec(dllexport)
#else
#define LP_BINDINGS_API __declspec(dllimport)
#endif
#else
#ifdef LP_BINDINGS_API_EXPORTS
#define LP_BINDINGS_API __attribute__((visibility("default")))
#else
#define LP_BINDINGS_API __attribute__((visibility("default")))
#endif
#endif