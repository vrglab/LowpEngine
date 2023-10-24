/* ======================================================================================== */
/* LowpEngine - Core C/C++ header file.														*/
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* The Debug class's implementation is based on the Log class from Hazel by Cherno          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

LP_Export class Debug
{
public:
	static int Init();
	static std::shared_ptr<spdlog::logger>& CoreLogger() { return s_CoreLogger; }
	static std::shared_ptr<spdlog::logger>& ClientLogger() { return s_ClientLogger; }
private:
	inline static std::shared_ptr<spdlog::logger> s_CoreLogger = spdlog::stdout_color_mt("LPENGINE");
	inline static std::shared_ptr<spdlog::logger> s_ClientLogger = spdlog::stdout_color_mt("APP");
};

#define LP_CORE_TRACE(...)  Debug::CoreLogger()->trace(__VA_ARGS__)
#define LP_CORE_INFO(...)   Debug::CoreLogger()->info(__VA_ARGS__)
#define LP_CORE_WARN(...)   Debug::CoreLogger()->warn(__VA_ARGS__)
#define LP_CORE_ERROR(...)  Debug::CoreLogger()->error(__VA_ARGS__)

// Client log macros
#define LP_TRACE(...)   Debug::ClientLogger()->trace(__VA_ARGS__)
#define LP_INFO(...)    Debug::ClientLogger()->info(__VA_ARGS__)
#define LP_WARN(...)    Debug::ClientLogger()->warn(__VA_ARGS__)
#define LP_ERROR(...)   Debug::ClientLogger()->error(__VA_ARGS__)