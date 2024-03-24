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

class FileAsset
{
public:
    std::string id, file_content;

    // Ignore this function as its used for serialization by cereal
    template<class Archive>
    void serialize(Archive& archive) {
        archive(file_content, id);
    }
};