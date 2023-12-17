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

LP_Export class Application
{
private:
	struct AppWindow
	{
	public:
		Ref<Window> created_window;
		void* created_rendering_framework;
		Ref<EventBus> event_buss;
	};
	Ref<AppWindow> created_window;
	Ref<ApplicationInfo> app_info;
	int CreateAppWindow(Ref<WindowCreateInfo>);

public:
	inline Ref<EventBus> GetEvenBuss() { return created_window->event_buss; }
	inline Ref<Window> GetWindow() { return created_window->created_window; }
	inline void* GetRenderingframework() { return created_window->created_rendering_framework; }
	int Init(Ref<ApplicationInfo> info);
	void Run();
	void CleanUp();
};

