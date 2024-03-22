/* ======================================================================================== */
/* LowpEngine - Asset Engine C/C++ header file.												*/
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>
#include "FileAsset.h"
#include <cereal/types/vector.hpp>

/**
 * @brief The batch containing the asset file content's
 */
class AssetsBatch
{
public:
	std::vector<FileAsset> assets;

	
	// Ignore this function as its used for serialization by cereal
	template <class Archive>
	void serialize(Archive& archive) {
		archive(assets);
	}
};

/**
 * @brief Finds asset files based on their GUID
 * @param id The GUID of the wanted asset
 * @param batch The Asset batch to search through
 * @return The assets raw file content if found a empty string if not
 */
LP_API std::string GetByGUID(std::string id, AssetsBatch batch);