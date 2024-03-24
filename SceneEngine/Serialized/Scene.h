/* ======================================================================================== */
/* LowpEngine - Scene Engine C/C++ header file.										        */
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>
#include "GameObject.h"

#include <cereal/types/vector.hpp>
#include <cereal/archives/binary.hpp>


/**
 * @brief Class for saving and loading a serialized Scene
 */
class Scene
{
public:
	std::vector<GameObject> game_objects;

    // Ignore this function as its used for serialization by cereal
    template<class Archive>
    void serialize(Archive& ar) {
        ar(game_objects);
    }
};