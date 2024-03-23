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


/**
 * @brief Class for saving and loading a serialized GameObject
 */
class GameObject
{
public:
	std::string guid, Name;
	std::vector<Component> components;

	// Ignore this function as its used for serialization by cereal
	template<class Archive>
	void serialize(Archive& ar) {
		ar(guid, Name, components);
	}
};

