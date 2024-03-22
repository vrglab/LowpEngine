/* ======================================================================================== */
/* LowpEngine - CoreBindings C/C++ header file.												*/
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>


LP_Extern LP_BINDINGS_API inline void _Log(char* msg);
LP_Extern LP_BINDINGS_API inline void _ErrLog(char* msg);
LP_Extern LP_BINDINGS_API inline void _WarnLog(char* msg);