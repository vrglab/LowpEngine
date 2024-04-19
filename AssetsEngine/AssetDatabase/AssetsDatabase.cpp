#include "pch.h"
#include "AssetsDatabase.h"
#include <filesystem>
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

        FileAsset asset{ generated_guid, fileContent };
        HRID hrid = { filePath.filename().string(), generated_guid };

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

    FileAsset asset = { generated_guid,  file };
    HRID hrid = { hrid_name, generated_guid };

    assets_batch.assets.push_back(asset);
    hrid_table.hrids.push_back(hrid);
}

std::string GetFileContentFromHRID(std::string hrid, AssetsDatabase database)
{
    return GetByGUID(GetGUIDFromHRID(hrid, database.hrid_table), database.assets_batch);
}

void AssetsDatabase::GenerateDatabaseFiles(HRIDTable hrid_table, AssetsBatch batch, std::string filepath, std::string  prefix)
{
    std::ofstream batch_stream = GenerateFile(filepath, prefix.append("primaryassetsbatch"));
    cereal::BinaryOutputArchive archive_batch(batch_stream);
    archive_batch(batch);

    std::ofstream hrid_stream = GenerateFile(filepath, prefix.append("hrid_table"));
    cereal::BinaryOutputArchive   archive_hrid(hrid_stream);
    archive_hrid(hrid_table);
}
