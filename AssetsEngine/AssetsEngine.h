/* ======================================================================================== */
/* LowpEngine - Asset Engine C/C++ header file.												*/
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once

#include <EngineCommons/EngineCommons.h>

//Asset Database
#include "AssetDatabase/AssetsDatabase.h"

#include <Core/Application/ApplicationInfo.h>

/*
 *
 * Engines Runtime Asset Databases
 *
 * The top variable is the database containing all of the games asset files (audio, video, drawings, game shader's,  misc files)
 * The bottom variable is the engine's default shader's
 */

extern LP_API AssetsDatabase assets_database;
extern LP_API AssetsDatabase default_shader_assets_database;

/**
 * @brief Primary class in charge of initializing the runtime's Asset system
 */
class LP_API AssetsEngine {

public:
	/**
	 * @brief Start's the runtime assets system's by loading all required asset database from .bin files
	 * @param info The Application starting info config
	 */
	static void StartAssetsEngine(Ref<ApplicationInfo> info);
};