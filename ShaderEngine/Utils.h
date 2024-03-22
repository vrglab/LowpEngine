/* ======================================================================================== */
/* LowpEngine - Shader Engine C/C++ header file.										    */
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>
#include <ShaderConductor/ShaderConductor.hpp>


class LP_API ShaderEngineUtils
{
public:
	static std::string ResolveShaderIncludes(std::string, std::string, std::vector<std::string>);
	static const void* CompileHLSLToSPIRV(std::string, std::string, std::string, ShaderConductor::ShaderStage, std::string);
};
