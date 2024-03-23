/* ======================================================================================== */
/* LowpEngine - Scene Engine C/C++ header file.										        */
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <cereal/types/string.hpp>

/**
 * @brief Class for saving and loading a serialized Component's variables
 */
class ComponentVariableData
{
public:
	std::string variable_id, variable_type;
	//Ref<void> variable_value;

    // Ignore this function as its used for serialization by cereal
    template<class Archive>
    void serialize(Archive& ar) {
        ar(variable_id, variable_type);
        // Handle variable_value manually or serialize metadata only.
    }
};

