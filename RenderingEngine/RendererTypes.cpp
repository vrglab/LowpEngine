#include "pch.h"
#include "RendererTypes.h"

LP_Export int getSystemSupportedRenderer()
{
#ifdef _WIN32 || __linux__
#ifdef __d3d12_h__ && _WIN32
		return RendererTypes::DirectX12;
#elif defined(vulkan)
		return RendererTypes::Vulkan;
#else
		return RendererTypes::OpenGL;
#endif
#endif
#ifdef __APPLE__
		return RendererTypes::Metal;
#endif
}
