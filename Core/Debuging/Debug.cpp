#include "pch.h"
#include "Debug.h"

int Debug::Init()
{
	spdlog::set_pattern("%^[%T] %n: %v%$");

	s_CoreLogger->set_level(spdlog::level::trace);

	s_ClientLogger->set_level(spdlog::level::trace);
    return LowpResultCodes::Success;
}
