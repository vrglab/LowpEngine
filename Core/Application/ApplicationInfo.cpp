#include "pch.h"
#include "ApplicationInfo.h"
#include <LowpEngine.h>

Ref<WindowCreateInfo> ApplicationInfo::GetWindowCreateInfo()
{
	Ref<WindowCreateInfo> created_ref = CreateRef<WindowCreateInfo>();
	created_ref->renderer_type = renderer_type;
	created_ref->tags = flags;
	created_ref->window_title = name;
	created_ref->resolution = resolution;
	return created_ref;
}

Ref<ApplicationInfo> ApplicationInfo::GetDefault()
{
	Ref<ApplicationInfo> create_info = CreateRef<ApplicationInfo>();
	create_info->renderer_type = getSystemSupportedRenderer();
	create_info->name = "Lowp Windows";
	create_info->ResourcesDir = getExecutablePath().append("\\").append("Lowp_data");

	create_info->resolution = CreateRef<Resolution>();
	create_info->resolution->height = 600;
	create_info->resolution->width = 1000;
	create_info->flags |= SDL_WINDOW_RESIZABLE;

	return create_info;
}
