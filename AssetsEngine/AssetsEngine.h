/* ======================================================================================== */
/* LowpEngine - Asset Engine C/C++ header file.												*/
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once

#include <cereal/cereal.hpp>

#include <EngineCommons/EngineCommons.h>

#include "FileAsset.h"
#include "AssetImporters/AssetImporter.h"

//Asset Database
#include "AssetDatabase/AssetsDatabase.h"

#include <Core/Debugging/Debug.h>
#include <Core/Application/ApplicationInfo.h>
#include <cereal/archives/binary.hpp>

static inline void StartAssetsEngine(Ref<ApplicationInfo> info)
{
	LP_CORE_INFO("Starting Assets Engine");
	LP_CORE_INFO(info->ResourcesDir);
}