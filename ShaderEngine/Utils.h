/* ======================================================================================== */
/* LowpEngine - Shader Engine C/C++ header file.										    */
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>
#include <Core/Debugging/Debug.h>

#include <ShaderConductor/ShaderConductor.hpp>

LP_Extern LP_API std::string ResolveShaderIncludes(std::string, std::string);
LP_Extern LP_API const void* CompileHLSLToSPIRV(std::string, std::string, std::string, ShaderConductor::ShaderStage);