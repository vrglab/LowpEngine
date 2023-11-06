/* ======================================================================================== */
/* LowpEngine - Core C/C++ header file.														*/
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>
#include "Windowing/Window.h"
#include "ApplicationInfo.h"

LP_Export class Application
{
private:
	Ref<Window> created_window;
	Ref<ApplicationInfo> app_info;

public:
	inline Ref<Window> GetWindow() { return created_window; }
	int Init(Ref<ApplicationInfo> info);
	void Run();
	void CleanUp();
};

