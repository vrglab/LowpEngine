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

class Scene
{
public:
	std::vector<GameObject> game_objects;

    template<class Archive>
    void serialize(Archive& ar) {
        ar(game_objects);
    }
};