/* ======================================================================================== */
/* LowpEngine - Engine Commons C/C++ header file.											*/
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once



class ConfigData
{
public:
	std::string id;
	void* value;
};


class Config
{
private:
	std::vector<ConfigData> configs = {};
public:
	void* GetConfig(std::string);
	void SetConfig(std::string, void*);
};

