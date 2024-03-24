#include "pch.h"
#include "AssetsEngine.h"
#include <fstream>
#include <cereal/archives/binary.hpp>

AssetsDatabase assets_database;
AssetsDatabase default_shader_assets_database;

void AssetsEngine::StartAssetsEngine(Ref<ApplicationInfo> info)
{
	LP_CORE_INFO("Starting Assets Engine");

	AssetsBatch batch;
	std::string assets_file = info->ResourcesDir;
	assets_file.append("\\primaryassetsbatch.bin");
	std::ifstream is_asset_file(assets_file, std::ios::binary);
	IFNERR(is_asset_file.good(), cereal::BinaryInputArchive archive(is_asset_file); archive(batch);, "Loading Failed: ", assets_file);

	HRIDTable hrid_table;
	std::string hrid_file = info->ResourcesDir;
	hrid_file.append("\\hrid_table.bin");
	std::ifstream is_hrid_file(hrid_file, std::ios::binary);
	IFNERR(is_hrid_file.good(), cereal::BinaryInputArchive archive(is_hrid_file); archive(hrid_table); , "Loading Failed: ", hrid_file);


	AssetsBatch shader_batch;
	std::string sh_assets_file = info->ResourcesDir;
	sh_assets_file.append("\\primarydefshaderassetsbatch.bin");
	std::ifstream is_sh_asset_file(sh_assets_file, std::ios::binary);
	IFNERR(is_sh_asset_file.good(), cereal::BinaryInputArchive archive(is_sh_asset_file); archive(shader_batch);, "Loading Failed: ", sh_assets_file);

	HRIDTable shader_hrid_table;
	std::string sh_hrid_file = info->ResourcesDir;
	sh_hrid_file.append("\\defshader_hrid_table.bin");
	std::ifstream is_sh_hrid_file(sh_hrid_file, std::ios::binary);
	IFNERR(is_sh_hrid_file.good(), cereal::BinaryInputArchive archive(is_sh_hrid_file); archive(shader_hrid_table); , "Loading Failed: ", sh_hrid_file);

	assets_database = { hrid_table, batch };
	default_shader_assets_database = { shader_hrid_table, shader_batch };
}