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

/**
 * @brief The primary class in charge of all of the sub-engine's and running the game
 */
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

	/**
	 * @brief Creates a new window for the application 
	 * @param info The configuration data of the window
	 * @return A LowpResultCodes of success upon successful creation
	 */
	int CreateAppWindow(Ref<WindowCreateInfo> info);

	/**
	 * @brief Initializes the application
	 * \param info The initialization configuration's
	 * \return A LowpResultCodes of success upon a successful init
	 */
	int Init(Ref<ApplicationInfo> info);

	/**
	 * @brief Call's the init function on all of the sub-engines
	 */
	void InitSubEngines();

	/**
	 * @brief Starts the main application loop
	 */
	void Run();

	/**
	 * @brief Shuts down all of the sub-engines and cleans the memory
	 */
	void CleanUp();
};

