/* ======================================================================================== */
/* LowpEngine - Asset Engine C/C++ header file.												*/
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>
#include "AssetsBatch.h"
#include "HRIDTable.h"

LP_Export class AssetsDatabase
{
public:
	HRIDTable hrid_table;
	AssetsBatch assets_batch;
	void ImportFileAsAsset(std::string);
	std::string GetFileContentFromHRID(std::string);
	static void GenerateDatabaseFiles(HRIDTable, AssetsBatch, std::string);
};