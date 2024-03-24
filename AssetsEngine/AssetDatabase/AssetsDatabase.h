/* ======================================================================================== */
/* LowpEngine - Asset Engine C/C++ header file.												*/
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>
#include <AssetsEngine/AssetsBatch.h>
#include <AssetsEngine/HRIDTable.h>

/**
 * @brief Database in charge of handling asset management in runtime
 */
class LP_API AssetsDatabase
{
public:
	HRIDTable hrid_table;
	AssetsBatch assets_batch;

	/**
	 * @brief Imports the given file into the assets database
	 * @param file_path The path to the file
	 */
	void ImportFileAsAsset(std::string file_path);

	/**
	 * @brief Imports a file using it's already loaded file content
	 * @param file The file content to import
	 * @param hrid The hrid to use for the file
	 */
	void ImportBufferedFileAsAsset(std::string file, std::string hrid);

	/**
	 * @brief Generates Asset Database files for runtime 
	 * @param hrid The hrid table of the database we are exporting
	 * @param batch The batch of file contents from the database that we are exporting
	 * @param path Where to export the files to
	 */
	static void GenerateDatabaseFiles(HRIDTable hrid, AssetsBatch batch, std::string path);
};

/**
 * @brief Attempt's to load a assets file content using it's hrid
 * @param hrid The hrid of the asset
 * @param database The database containing the asset
 * @return The found raw file bytes
 */
LP_API std::string GetFileContentFromHRID(std::string hrid, AssetsDatabase database);