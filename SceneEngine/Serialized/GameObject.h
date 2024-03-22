/* ======================================================================================== */
/* LowpEngine - Scene Engine C/C++ header file.										        */
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include "Component/Component.h"

#include <fstream>

class GameObject
{
public:
	std::string guid, Name;
	std::vector<Component> components;

	template<class Archive>
	void serialize(Archive& ar) {
		ar(guid, Name, components);
	}
};

