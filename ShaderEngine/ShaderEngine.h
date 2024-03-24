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

/**
 * @brief Primary class in charge of handling Shaders
 */
class ShaderEngine
{
public:
	/**
	 * @brief Compiles all .hlsl shaders contained within a directory
	 * @param shaders_dir The directory to search for .hlsl files
	 * @param includes_dir the directory to include dependencies
	 */
	static void CompileShadersForReleaseCompilation(std::string shaders_dir, std::vector<std::string> includes_dir);

	/**
	 * @brief Get's The type of a shader based on it's name
	 * @param filename the shader's file name
	 * @return The found type
	 */
	static ShaderConductor::ShaderStage GetShaderStage(std::string filename);
};