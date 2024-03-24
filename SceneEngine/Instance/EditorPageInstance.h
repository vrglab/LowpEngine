/* ======================================================================================== */
/* LowpEngine - Scripting Engine C/C++ header file.											*/
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>
#include <ScriptingEngine/EditorPageType.h>

/**
 * @brief The editor-time instance of a editor page
 */
class EditorPageInstance {
public:
	EditorPageType page_type;
	std::string id;
	MonoObject* instance;

	/**
	 * @brief Render call of a page for ImGui
	 */
	void render();
};