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
public:
	std::vector<FileAsset> assets;
	std::string GetByGUID(std::string);

	template <class Archive>
	void serialize(Archive& archive) {
		archive(assets);
	}
};