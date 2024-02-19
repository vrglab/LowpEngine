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

//Asset Database
#include "AssetDatabase/AssetsDatabase.h"

#include "AssetsBatch.h"
#include "HRIDTable.h"

#include <fstream>
#include <Core/Debugging/Debug.h>
#include <Core/Application/ApplicationInfo.h>

extern LP_API AssetsDatabase assets_database;

class AssetsEngine {

public:
	static void StartAssetsEngine(Ref<ApplicationInfo> info);
};