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
#include <AssetsEngine/AssetsEngine.h>
#include <filesystem>

namespace fs = std::filesystem;

#include "Utils.h"

LP_API char vertex_filename[] = {'v', 'r', 't'};
LP_API char fragment_filename[] = { 'f', 'r', 'a' };
LP_API char geometry_filename[] = { 'g', 'e', 'o' };
LP_API char hull_filename[] = { 'h', 'u', 'l' };
LP_API char domain_filename[] = { 'd', 'o', 'm' };
LP_API char compute_filename[] = { 'c', 'o', 'm' };
LP_API char num_filename[] = { 'n', 'u', 'm' };

LP_Extern LP_API void CompileShadersForReleaseCompilation(std::string, std::string);
LP_Extern LP_API ShaderConductor::ShaderStage GetShaderStage(std::string);