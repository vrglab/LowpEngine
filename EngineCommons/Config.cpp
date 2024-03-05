#include "pch.h"
#include "Config.h"

void* Config::GetConfig(std::string id)
{
	for (size_t i = 0; i < configs.size(); i++)
	{
		if (configs[i].id == id) {
			return configs[i].value;
		}
	}
	return nullptr;
}

void Config::SetConfig(std::string id, void* val)
{
	for (size_t i = 0; i < configs.size(); i++)
	{
		if (configs[i].id == id) {
			configs[i].value = val;
			return;
		}
	}

	ConfigData sic = {};
	sic.id = id;
	sic.value = val;
	configs.push_back(sic);
}