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
#include <cereal/types/memory.hpp>
#include <cereal/types/string.hpp>

struct ConfigsData {
public:
	std::string app_name;
	int res_w, res_h;
	template<class Archive>
	void serialize(Archive& archive)
	{
		archive(app_name, res_w, res_h);
	}
};