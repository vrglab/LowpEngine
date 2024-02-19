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

LP_Extern class AssetsDatabase
{
public:
	HRIDTable hrid_table;
	AssetsBatch assets_batch;
	LP_API void ImportFileAsAsset(std::string);
	LP_API static void GenerateDatabaseFiles(HRIDTable, AssetsBatch, std::string);
};

LP_Extern LP_API std::string GetFileContentFromHRID(std::string, AssetsDatabase);