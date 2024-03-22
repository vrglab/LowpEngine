/* ======================================================================================== */
/* LowpEngine - Rendering Engine C/C++ header file.										    */
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>
#include <SDL2/SDL.h>
#include <Core/Application/ApplicationInfo.h>

/**
 * @brief Base class for all rendering frameworks
 */
class Framework
{
protected:
	SDL_Window* window_access;
public:
	/**
	 * @brief Function called when SDL2 is being initialized
	 */
	virtual void OnSdlSetup() = 0;

	/**
	 * @brief Function called when application is being initialized
	 * @param info The starting configs of the application
	 * @param window the created sdl2 window
	 */
	virtual void Init(Ref<ApplicationInfo> info, SDL_Window* window) = 0;

	/**
	 * @brief The applications runtime rendering call
	 */
	virtual void Tick() = 0;
#ifdef EDITOR
	virtual void CleanWindow() = 0;
#endif
	/**
	 * @brief Swaps the Windows rendering buffers
	 */
	virtual void SwapWindow() = 0;

	/**
	 * @brief Cleans up the memory from the renderer
	 */
	virtual void Cleanup() = 0;
};