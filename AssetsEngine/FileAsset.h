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
private:
	char* file_content;
	std::string name;
	int importer_type;
public:
    template<class Archive>
    void save(Archive& archive) const {
        std::string content = file_content ? file_content : "";
        archive(content, name, importer_type);
    }

    template<class Archive>
    void load(Archive& archive) {
        std::string content;
        archive(content, name, importer_type);
        // Ensure to deallocate old file_content and allocate new memory
        delete[] file_content;
        file_content = new char[content.size() + 1];
        std::copy(content.begin(), content.end(), file_content);
        file_content[content.size()] = '\0'; // Null-terminate
    }
};