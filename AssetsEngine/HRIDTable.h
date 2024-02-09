/* ======================================================================================== */
/* LowpEngine - Asset Engine C/C++ header file.												*/
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>
#include <cereal/types/string.hpp>
#include <cereal/types/memory.hpp>
#include <cereal/types/vector.hpp>

LP_Export struct HRID
{

public:
    std::string hrid;
    std::string guid;
    template<class Archive>
    void serialize(Archive& archive) {
        archive(hrid, guid);
    }
};

LP_Export struct HRIDTable
{
public:
    std::vector<HRID> hrids;
    template<class Archive>
    void serialize(Archive& archive) {
        archive(hrids);
    }
};
