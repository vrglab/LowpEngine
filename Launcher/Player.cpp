#include "pch.h"
#include "Player.h"
#include <fstream>


Ref<ApplicationInfo> Player::LoadAppData()
{
    Ref<ApplicationInfo> create_info = CreateRef<ApplicationInfo>();

    std::ifstream config_file_stream("\\Lowp_data\\config.bin", std::ios::binary);


    return create_info;
}
