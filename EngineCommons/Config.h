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

/**
 * @brief Class to hold custom configs data for various uses
 */
class Config
{
private:
	std::vector<ConfigData> configs = {};
public:
	/**
	 * @brief Finds the given config and returns it's saved value
	 * @param conf The wanted configs name/id
	 * @return the configs saved value
	 */
	void* GetConfig(std::string conf);

	/**
	 * @brief Saves a config using the given name/id and value
	 * @param conf The name/id to set for the config
	 * @param val The config value
	 */
	void SetConfig(std::string conf, void* val);
};

