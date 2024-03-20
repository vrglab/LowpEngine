/* ======================================================================================== */
/* LowpEngine - Core C/C++ header file.														*/
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once

#ifndef _lpEngine_
#define _lpEngine_

//Debugging
#include "Debugging/Debug.h"

//Engine Commons
#include <EngineCommons/EngineCommons.h>

#include <SceneEngine/SceneManager.h>

//Rendering Engine
#include <RenderingEngine/RenderingEngine.h>

//Events
#include <EventEngine/EventEngine.h>

//Windowing
#include "Windowing/Resolution.h"
#include "Windowing/WindowCreateInfo.h"
#include "Windowing/Window.h"

//Application
#include "Application/ApplicationInfo.h"
#include "Application/Application.h"

//Assets
#include <AssetsEngine/AssetsEngine.h>

//Shader Compilers
#include <ShaderEngine/ShaderEngine.h>

//Scripting
#include <ScriptingEngine/ScriptingEngine.h>

//Audio
#include <SoundEngine/SoundEngine.h>

//Physics
#include <PhysicsEngine/PhysicsEngine.h>

//Scene
#include <SceneEngine/SceneManager.h>

#endif