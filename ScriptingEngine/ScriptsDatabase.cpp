#include "pch.h"
#include "ScriptsDatabase.h"

MonoClass* ScriptsDatabase::GetLoadedScript(std::string id)
{
	for (size_t i = 0; i < scripts.size(); i++)
	{
		LoadedScript script = scripts[i];
		if (script.engine_id == id) {
			return script.loaded_class_type;
		}
	}
	return nullptr;
}
