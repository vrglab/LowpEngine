/* ======================================================================================== */
/* LowpEngine - Scene Engine C/C++ header file.										        */
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>
#include "ComponentVariableData.h"

#include <cereal/types/vector.hpp>

class Component
{
public:
	std::string engine_id;
	std::vector<ComponentVariableData> data;

	template<class Archive>
	void serialize(Archive& ar) {
		ar(engine_id, data);
	}
};

