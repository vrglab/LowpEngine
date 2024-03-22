#include "pch.h"
#include "AssetsDatabase.h"
#include <fstream>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <cereal/cereal.hpp>
#include <cereal/archives/binary.hpp>

namespace fs = std::filesystem;

void AssetsDatabase::ImportFileAsAsset(std::string file)
{
	fs::path filePath = file;
    if (fs::exists(filePath)) {
        std::ifstream fileStream(filePath);
        IFERR(!fileStream, "Failed to open file: ", filePath.string());

        std::string fileContent((std::istreambuf_iterator<char>(fileStream)),
            std::istreambuf_iterator<char>());

        std::string generated_guid = GUIDGen();

        FileAsset asset;
        asset.id = generated_guid;

        HRID hrid;
        hrid.hrid = filePath.filename().string();
        hrid.guid = generated_guid;

        asset.file_content = fileContent;

        assets_batch.assets.push_back(asset);
        hrid_table.hrids.push_back(hrid);
    }
    else {
        std::string err_msg = "File can't be found: ";
        err_msg.append(filePath.string());
        LP_CORE_ERROR(err_msg);
    }
}

void AssetsDatabase::ImportBufferedFileAsAsset(std::string file, std::string hrid_name)
{
    std::string generated_guid = GUIDGen();

    FileAsset asset;
    asset.id = generated_guid;

    HRID hrid;
    hrid.hrid = hrid_name;
    hrid.guid = generated_guid;

    asset.file_content = file;

    assets_batch.assets.push_back(asset);
    hrid_table.hrids.push_back(hrid);
}

std::string GetFileContentFromHRID(std::string hrid, AssetsDatabase database)
{
    return GetByGUID(GetGUIDFromHRID(hrid, database.hrid_table), database.assets_batch);
}

void AssetsDatabase::GenerateDatabaseFiles(HRIDTable hrid_table, AssetsBatch batch, std::string filepath)
{
    std::string a_path = filepath;
    std::string b_path = filepath;

    std::ofstream  hrid_file_stream(a_path.append("hrid_table.bin").c_str(), std::ios::binary);
    IFERRTHROW(!hrid_file_stream.is_open(), "Failed to open batch file for writing.");

    cereal::BinaryOutputArchive   archive_hrid(hrid_file_stream);
    archive_hrid(hrid_table);


    std::ofstream  batch_file_stream(b_path.append("primaryassetsbatch.bin").c_str(), std::ios::binary);
    IFERRTHROW(!batch_file_stream.is_open(), "Failed to open hrid file for writing.");

    cereal::BinaryOutputArchive   archive_batch(batch_file_stream);
    archive_batch(batch);
}
