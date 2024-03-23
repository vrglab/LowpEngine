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
	/**
	 * @brief Finds and resolves all #include in a .hlsl file
	 * \param source The hlsl source
	 * \param include_paths All of the possible directories the #include's path could be at
	 * \param resolved_includes Already found and memory loaded #include's
	 * \return The processed source
	 */
	static std::string ResolveShaderIncludes(std::string source, std::vector<std::string> include_paths, std::vector<std::string> resolved_includes);
	
	/**
	 * @brief Takes a hlsl source and compiles it into spirv for better cross-platform usage
	 * @param source_unprocessed The raw loaded shader source 
	 * @param include_paths all of the dependency path's
	 * @param entryPoint the shaders entry point
	 * @param shader_type The shader's types
	 * @param filename The shader files name
	 * @return The compiled SPIRV data
	 */
	static const void* CompileHLSLToSPIRV(std::string source_unprocessed, std::vector<std::string> include_paths, std::string entryPoint,
		ShaderConductor::ShaderStage shader_type, std::string filename);
};
