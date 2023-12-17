#include "pch.h"
#include "Application.h"
#include <RenderingEngine/FrameworkHandeling/Frameworks/OpenGLFramework.h>
#include <RenderingEngine/FrameworkHandeling/Frameworks/Directx12Framework.h>
#include <RenderingEngine/FrameworkHandeling/Frameworks/VulkanFramework.h>

int Application::Init(Ref<ApplicationInfo> info)
{
    LP_CORE_INFO("Starting engine");
    app_info = info;
    CreateAppWindow(info->GetWindowCreateInfo());

    return LowpResultCodes::Success;
}

void Application::Run()
{
   
    while (!GetWindow()->ShouldClose())
    {
        created_window->created_window->ProcessEvents();
        created_window->event_buss->ResolveQue();
        ((Framework*)created_window->created_rendering_framework)->Tick();
        ((Framework*)created_window->created_rendering_framework)->SwapWindow();
    }
    
}

int Application::CreateAppWindow(Ref<WindowCreateInfo> info)
{
    Ref<AppWindow> app_window = CreateRef<AppWindow>();
    Ref<Window> created_windo = CreateRef<Window>();

    if (created_windo->Init(info) != LowpResultCodes::Success)
    {
        LP_CORE_ERROR("Window initiation failed");
        return LowpResultCodes::UnknowError;
    }

    switch (info->renderer_type)
    {
    case RendererTypes::DirectX12:
        app_window->created_rendering_framework = new Directx12Framework();
        break;
    case RendererTypes::Vulkan:
        app_window->created_rendering_framework = new VulkanFramework();
        break;
    case RendererTypes::OpenGL:
        app_window->created_rendering_framework = new OpenGLFramework();
        break;
    case RendererTypes::Metal:
        break;
    }
    ((Framework*)app_window->created_rendering_framework)->Init(app_info, created_windo->getSdlWindow());

    app_window->event_buss = CreateRef<EventBus>();

    created_windo->ShowWindow();
    app_window->created_window = created_windo;
    created_window = app_window;
    return LowpResultCodes::Success;
}

void Application::CleanUp()
{
    LP_CORE_INFO("Closing engine");
    ((Framework*)created_window->created_rendering_framework)->Cleanup();
    created_window->created_window->CleanUp();
}
