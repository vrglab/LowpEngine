/* ======================================================================================== */
/* LowpEngine - Core C/C++ header file.														*/
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>
#include <RenderingEngine/FrameworkHandeling/Framework.h>
#include "Windowing/Window.h"
#include "ApplicationInfo.h"

class LP_API Application
{
private:
	struct AppWindow
	{
	public:
		Ref<Window> created_window;
		void* created_rendering_framework;
		Ref<EventBus> event_buss;
	};
	Ref<AppWindow> window_data;

public:
	Ref<ApplicationInfo> app_info;
	int CreateAppWindow(Ref<WindowCreateInfo>);
	int Init(Ref<ApplicationInfo> info);
	void InitSubEngines();
	void Run();
	void CleanUp();
};

