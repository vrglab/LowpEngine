/* ======================================================================================== */
/* LowpEngine - Core C/C++ header file.														*/
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */

//LP_EXPORT
#ifdef _WIN32
#define LP_Export __declspec(dllexport)
#else
#define LP_Export __attribute__((visibility("default")))
#endif

//LP_EXTERN
#define LP_Extern extern "C"
