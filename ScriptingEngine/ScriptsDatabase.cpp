#include "pch.h"
#include "ScriptsDatabase.h"

MonoClass* ScriptsDatabase::GetLoadedScript(std::string id)
{
#ifdef GAME
	for (size_t i = 0; i < scripts.size(); i++)
	{
		LoadedScript script = scripts[i];
		if (script.engine_id == id) {
			return script.loaded_class_type;
		}
	}
#endif
#ifdef EDITOR
	for (size_t i = 0; i < scripts.size(); i++)
	{
		EditorPageType script = scripts[i];
		if (script.page_id == id) {
			return script.loaded_class_type;
		}
	}
#endif
	return nullptr;
}

#ifdef EDITOR
EditorPageType ScriptsDatabase::GetLoadedScript_(std::string id)
{
	for (size_t i = 0; i < scripts.size(); i++)
	{
		EditorPageType script = scripts[i];
		if (script.page_id == id) {
			return script;
		}
	}
}
#endif
