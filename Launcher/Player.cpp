#include "pch.h"
#include "Player.h"
#include <fstream>


Ref<ApplicationInfo> Player::LoadAppData()
{
    Ref<ApplicationInfo> create_info = CreateRef<ApplicationInfo>();

    std::ifstream inFile("Player Data/appInfo.bin", std::ios::binary); // Open the binary file


    return create_info;
}
