/* ======================================================================================== */
/* LowpEngine - Sound Engine C/C++ header file.												*/
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>

LP_API enum SoundSystemBackendType {
	OpenAL = 0,
	FMOD = 1
};

LP_API enum SoundSystemType {
	Stereo = 0,
	Mono = 1,
	Five_Point_One = 2,
	Six_Point_One = 3
};