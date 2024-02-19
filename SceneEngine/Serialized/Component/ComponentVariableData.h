/* ======================================================================================== */
/* LowpEngine - Scene Engine C/C++ header file.										        */
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>
#include <mono/metadata/object.h>

#include <cereal/types/vector.hpp>
#include <cereal/types/string.hpp>
#include <cereal/archives/binary.hpp>
#include <fstream>

class ComponentVariableData
{
public:
	std::string variable_id, variable_type;
	//Ref<void> variable_value;

    template<class Archive>
    void serialize(Archive& ar) {
        ar(variable_id, variable_type);
        // Handle variable_value manually or serialize metadata only.
    }
};

