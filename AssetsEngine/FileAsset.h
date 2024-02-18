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

LP_Export class FileAsset
{
public:
    std::string id, file_content;

    template<class Archive>
    void serialize(Archive& archive) {
        archive(file_content, id);
    }
};