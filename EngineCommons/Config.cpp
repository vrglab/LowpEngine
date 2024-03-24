#include "pch.h"
#include "Config.h"

void* Config::GetConfig(std::string conf)
{
	for (size_t i = 0; i < configs.size(); i++)
	{
		if (configs[i].id == conf) {
			return configs[i].value;
		}
	}
	return nullptr;
}

void Config::SetConfig(std::string conf, void* val)
{
	for (size_t i = 0; i < configs.size(); i++)
	{
		if (configs[i].id == conf) {
			configs[i].value = val;
			return;
		}
	}

	ConfigData sic = {};
	sic.id = conf;
	sic.value = val;
	configs.push_back(sic);
}