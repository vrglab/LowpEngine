#include "pch.h"
#include "RendererTypes.h"
#include "FrameworkHandeling/Framework.h"
#include "FrameworkHandeling/Frameworks/OpenGLFramework.h"

LP_Export int getSystemSupportedRenderer()
{
#if defined(_WIN32)
	return RendererTypes::DirectX12;
#endif

#ifdef __APPLE__
	return RendererTypes::Metal;
#endif

#if defined(__linux_)
#if defined(vulkan)
		return RendererTypes::Vulkan;
#else
		return RendererTypes::OpenGL;
#endif
#endif
}