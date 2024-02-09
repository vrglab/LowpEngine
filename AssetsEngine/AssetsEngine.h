/* ======================================================================================== */
/* LowpEngine - Asset Engine C/C++ header file.												*/
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once

#include <cereal/cereal.hpp>

#include <EngineCommons/EngineCommons.h>

#include "FileAsset.h"
#include "AssetImporters/AssetImporter.h"

//Asset Database
#include "AssetDatabase/AssetsDatabase.h"

#include "AssetsBatch.h"

#include <fstream>
#include <Core/Debugging/Debug.h>
#include <Core/Application/ApplicationInfo.h>
#include <cereal/archives/portable_binary.hpp>

static inline void StartAssetsEngine(Ref<ApplicationInfo> info)
{
	LP_CORE_INFO("Starting Assets Engine");

	AssetsBatch batch;
	std::string assets_file = info->ResourcesDir;
	assets_file.append("\\primaryassetsbatch.bin");
	std::ifstream is(assets_file, std::ios::binary);
	if(is.good())
	{
		cereal::PortableBinaryInputArchive inArchive(is);
		inArchive(batch);
	}

	LP_CORE_INFO(assets_file);
}