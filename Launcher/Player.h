/* ======================================================================================== */
/* LowpEngine - Launcher C/C++ header file.											        */
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/*																						    */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>
#include <Core/Application/ApplicationInfo.h>
#include "ConfigsData.h"

LP_Export class Player
{
public:
	static Ref<ApplicationInfo> LoadAppData();
	static Ref<ApplicationInfo> MakeAppData(ConfigsData data, std::string);
};