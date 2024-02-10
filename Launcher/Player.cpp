#include "pch.h"
#include "Player.h"
#include <fstream>
#include <cereal/archives/binary.hpp>


Ref<ApplicationInfo> Player::LoadAppData()
{
    ConfigsData data;
    Ref<ApplicationInfo> app_info = ApplicationInfo::GetDefault();

    std::string path_to_config_file = app_info->ResourcesDir;
    path_to_config_file.append("\\config.bin");
    std::ifstream config_file_stream(path_to_config_file.c_str(), std::ios::binary);
    cereal::BinaryInputArchive  archive(config_file_stream);
    archive(data);

    app_info->name = data.app_name;
    app_info->resolution->width = data.res_w;
    app_info->resolution->height = data.res_h;

    return app_info;
}

Ref<ApplicationInfo> Player::MakeAppData(ConfigsData data, std::string path)
{
    std::ofstream  config_file_stream(path.c_str(), std::ios::binary);
    if (!config_file_stream.is_open()) {
        throw std::runtime_error("Failed to open config file for writing.");
    }
    cereal::BinaryOutputArchive   archive(config_file_stream);
    archive(data);

    Ref<ApplicationInfo> app_info = ApplicationInfo::GetDefault();
    app_info->name = data.app_name;
    app_info->resolution->width = data.res_w;
    app_info->resolution->height = data.res_h;

    return app_info;
}