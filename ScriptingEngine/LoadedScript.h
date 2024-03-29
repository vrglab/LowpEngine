/* ======================================================================================== */
/* LowpEngine - Scripting Engine C/C++ header file.											*/
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>
#include <mono/metadata/class.h>

/**
 * @brief The Main class to represent a memory loaded C# class within the engine
 */
class LoadedScript
{
public:
	std::string engine_id;
	MonoClass* loaded_class_type;
};

