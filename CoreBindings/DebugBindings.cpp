#include "pch.h"
#include "DebugBindings.h"

LP_Extern LP_BINDINGS_API void _Log(char* msg)
{
	LP_INFO(msg);
}

LP_Extern LP_BINDINGS_API void _ErrLog(char* msg)
{
	LP_ERROR(msg);
}

LP_Extern LP_BINDINGS_API void _WarnLog(char* msg)
{
	LP_WARN(msg);
}
