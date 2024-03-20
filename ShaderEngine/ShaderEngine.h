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

static char vertex_filename[] = {'v', 'r', 't'};
static char fragment_filename[] = { 'f', 'r', 'a' };
static char geometry_filename[] = { 'g', 'e', 'o' };
static char hull_filename[] = { 'h', 'u', 'l' };
static char domain_filename[] = { 'd', 'o', 'm' };
static char compute_filename[] = { 'c', 'o', 'm' };
static char num_filename[] = { 'n', 'u', 'm' };

class ShaderEngine
{
public:
	static void Dummy();
	static void CompileShadersForReleaseCompilation(std::string, std::string);
	static ShaderConductor::ShaderStage GetShaderStage(std::string);
};