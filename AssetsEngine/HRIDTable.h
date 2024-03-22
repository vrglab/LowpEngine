/* ======================================================================================== */
/* LowpEngine - Asset Engine C/C++ header file.												*/
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>
#include <cereal/types/vector.hpp>

/**
 * @brief Human readable identifier (HRID)
 */
struct HRID
{

public:
    std::string hrid;
    std::string guid;

    // Ignore this function as its used for serialization by cereal
    template<class Archive>
    void serialize(Archive& archive) {
        archive(hrid, guid);
    }
};

/**
 * @brief a list HRID's for the Asset Database 
 */
struct HRIDTable
{
public:
    std::vector<HRID> hrids;

    // Ignore this function as its used for serialization by cereal
    template<class Archive>
    void serialize(Archive& archive) {
        archive(hrids);
    }
};

/**
 * @brief Finds a asset files GUID based on the HRID
 * @param hrid The HRID of the asset file we want
 * @param table The HRID database holding the guid of the asset
 * @return The found GUID, empty if nothing found
 */
LP_API std::string GetGUIDFromHRID(std::string hrid, HRIDTable table);