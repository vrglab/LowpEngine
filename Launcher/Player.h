/* ======================================================================================== */
/* LowpEngine - Launcher C/C++ header file.											*/
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* The assert implementation is based on the assert implementation from Hazel by Cherno     */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>
#include <Core/Application/ApplicationInfo.h>

LP_Export class Player
{
public:
	static Ref<ApplicationInfo> LoadAppData();
};

