#include "pch.h"
#include "Application.h"
#include <RenderingEngine/FrameworkHandeling/Frameworks/OpenGLFramework.h>

int Application::Init(Ref<ApplicationInfo> info)
{
    LP_CORE_INFO("Starting engine");
    created_window = CreateRef<Window>();
    if (created_window->Init(info->GetWindowCreateInfo()) != LowpResultCodes::Success) 
    {
        LP_CORE_ERROR("Window initiation failed");
        return LowpResultCodes::UnknowError;
    }
    created_window->ShowWindow();

    switch (info->renderer_type)
    {
    case RendererTypes::DirectX12:
        break;
    case RendererTypes::Vulkan:
        break;
    case RendererTypes::OpenGL:
        created_rendering_framework = new OpenGLFramework();
        break;
    case RendererTypes::Metal:
        break;
    }

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
    }
}

void Application::CleanUp()
{
    LP_CORE_INFO("Closing engine");
    created_window->CleanUp();
}
