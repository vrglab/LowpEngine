#include "pch.h"
#include "MetalFramework.h"

void MetalFramework::Init(Ref<ApplicationInfo>, SDL_Window*)
{
#ifdef __APPLE__
    CAMetalLayer* metalLayer = (CAMetalLayer*)SDL_Metal_CreateView(window);
    device = MTLCreateSystemDefaultDevice();
    metalLayer.device = device;
    metalLayer.pixelFormat = MTLPixelFormatBGRA8Unorm;
    commandQueue = [device newCommandQueue];
#else
    LP_CORE_ERROR("Metal not supported on this device");
#endif
}

void MetalFramework::Tick()
{
#ifdef __APPLE__
    id<MTLCommandBuffer> commandBuffer = [commandQueue commandBuffer];

    [commandBuffer presentDrawable : drawable];
    [commandBuffer commit];
#endif
}

void MetalFramework::SwapWindow()
{
}

#ifdef EDITOR
void MetalFramework::CleanWindow()
{
}
#endif

void MetalFramework::Cleanup()
{
}

void MetalFramework::OnSdlSetup()
{
}
