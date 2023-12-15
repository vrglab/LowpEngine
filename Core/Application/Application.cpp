#include "pch.h"
#include "Application.h"
#include <RenderingEngine/FrameworkHandeling/Frameworks/OpenGLFramework.h>
#include <RenderingEngine/FrameworkHandeling/Frameworks/Directx12Framework.h>

int Application::Init(Ref<ApplicationInfo> info)
{
    LP_CORE_INFO("Starting engine");
    created_window = CreateRef<Window>();

    if (created_window->Init(info->GetWindowCreateInfo()) != LowpResultCodes::Success) 
    {
        LP_CORE_ERROR("Window initiation failed");
        return LowpResultCodes::UnknowError;
    }

    switch (info->renderer_type)
    {
    case RendererTypes::DirectX12:
        created_rendering_framework = new Directx12Framework();
        break;
    case RendererTypes::Vulkan:
        break;
    case RendererTypes::OpenGL:
        created_rendering_framework = new OpenGLFramework();
        break;
    case RendererTypes::Metal:
        break;
    }
    ((Framework*)created_rendering_framework)->Init(info, created_window->getSdlWindow());

    created_window->ShowWindow();


    created_window->window_resize_event = CreateRef<EventHandler>();
    event_buss = CreateRef<EventBus>(); 

    return LowpResultCodes::Success;
}

void Application::Run()
{
    while (!created_window->ShouldClose()) 
    {
        created_window->ProcessEvents();
		GetEvenBuss()->ResolveQue();
        ((Framework*)created_rendering_framework)->Tick();
        ((Framework*)created_rendering_framework)->SwapWindow();
    }
}

void Application::CleanUp()
{
    LP_CORE_INFO("Closing engine");
    ((Framework*)created_rendering_framework)->Cleanup();
    created_window->CleanUp();
}
