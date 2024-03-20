/* ======================================================================================== */
/* LowpEngine - Engine Commons C/C++ header file.											*/
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include "Macros.h"
#include <string>

LP_API std::string read_bytes(const std::string& filepath);
LP_API std::string getExecutablePath();
LP_API std::string GUIDGen();