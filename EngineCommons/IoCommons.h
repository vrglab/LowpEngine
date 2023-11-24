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

LP_Export char* read_bytes(const std::string& filepath, uint32_t* outSize);