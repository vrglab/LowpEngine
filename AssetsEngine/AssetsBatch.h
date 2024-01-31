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
#include <cereal/types/memory.hpp>
#include <cereal/types/vector.hpp>

class AssetsBatch
{
private:
	std::vector<FileAsset> assets;
public:
	/**
	 * \brief Return's a std::vector of FileAssets loaded from a batch file
	 */
	std::vector<FileAsset> get_assets();

	template <class Archive>
	void serialize(Archive& archive) {
		archive(assets);
	}
};