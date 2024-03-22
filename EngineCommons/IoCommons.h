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

/**
 *	@brief Helper function to generate.bin files
 *  @param filepath Path to the directory the file should be generated in
 *	@param filename The name to use for the file generation
 *	@return The function returns a open stream on success and throws a runtime error on failure
 */
LP_API std::ofstream GenerateFile(std::string filepath, std::string filename);

LP_API std::vector<std::string> splitString(const std::string& text, char delim);

LP_API std::string joinExceptLast(const std::string& text, char delim);