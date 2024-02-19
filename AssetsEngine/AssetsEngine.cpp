#include "pch.h"
#include "AssetsEngine.h"
#include <Core/Debugging/Debug.h>
#include <fstream>
#include <cereal/archives/binary.hpp>

AssetsDatabase assets_database;

void AssetsEngine::StartAssetsEngine(Ref<ApplicationInfo> info)
{
	LP_CORE_INFO("Starting Assets Engine");

	AssetsBatch batch;
	std::string assets_file = info->ResourcesDir;
	assets_file.append("\\primaryassetsbatch.bin");
	std::ifstream is_asset_file(assets_file, std::ios::binary);
	if (is_asset_file.good())
	{
		cereal::BinaryInputArchive archive(is_asset_file);
		archive(batch);
	}

	HRIDTable hrid_table;
	std::string hrid_file = info->ResourcesDir;
	hrid_file.append("\\hrid_table.bin");
	std::ifstream is_hrid_file(hrid_file, std::ios::binary);
	if (is_hrid_file.good())
	{
		cereal::BinaryInputArchive archive(is_hrid_file);
		archive(hrid_table);
	}

	assets_database = { hrid_table, batch };
}