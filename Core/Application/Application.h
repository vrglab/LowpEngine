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
	Ref<Window> created_window;
	void* created_rendering_framework;
	Ref<ApplicationInfo> app_info;
	static inline Ref<EventBus> event_buss = 0;

public:
	static Ref<EventBus> GetEvenBuss() { return event_buss; }
	inline Ref<Window> GetWindow() { return created_window; }
	inline void* GetRenderingframework() { return created_rendering_framework; }
	int Init(Ref<ApplicationInfo> info);
	void Run();
	void CleanUp();
};

