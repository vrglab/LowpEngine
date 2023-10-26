#include "pch.h"
#include "ApplicationInfo.h"

Ref<WindowCreateInfo> ApplicationInfo::GetWindowCreateInfo()
{
	Ref<WindowCreateInfo> created_ref = CreateRef<WindowCreateInfo>();
	created_ref->renderer_type = renderer_type;
	created_ref->tags = flags;
	created_ref->window_title = name;
	created_ref->resolution = resolution;
	return created_ref;
}
