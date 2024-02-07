#include "pch.h"
#include "DebugBindings.h"

LP_Export void Log(std::string msg)
{
    LP_INFO(msg.c_str());
}
