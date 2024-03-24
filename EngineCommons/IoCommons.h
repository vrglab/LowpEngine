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

/**
 * @brief Open's and read's a files data
 * @return The file data
 */
LP_API std::string read_bytes(const std::string& filepath);

/**
 * @brief Get's the applications working directory
 * @return The found path
 */
LP_API std::string getExecutablePath();

/**
 * @brief Generates a GUID everytime it's called
 * @return The generated GUID
 */
LP_API std::string GUIDGen();

/**
 *	@brief Helper function to generate.bin files
 *  @param filepath Path to the directory the file should be generated in
 *	@param filename The name to use for the file generation
 *	@return The function returns a open stream on success and throws a runtime error on failure
 */
LP_API std::ofstream GenerateFile(std::string filepath, std::string filename);

/**
 * @brief Split's a std::string using a given char
 * @param text the text to split
 * @param delim the char to use as separator
 * @return the split string
 */
LP_API std::vector<std::string> splitString(const std::string& text, char delim);

/**
 * @brief Separates the  given string using the given char and then re-attaches all of the string using the same given char except the very last split item
 * @param text The string to process
 * @param delim The separator
 * @return The processed string
 */
LP_API std::string joinExceptLast(const std::string& text, char delim);




