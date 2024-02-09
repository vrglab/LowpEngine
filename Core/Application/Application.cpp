#include "pch.h"
#include "Application.h"
#include <RenderingEngine/FrameworkHandeling/Frameworks/OpenGLFramework.h>
#include <RenderingEngine/FrameworkHandeling/Frameworks/Directx12Framework.h>
#include <RenderingEngine/FrameworkHandeling/Frameworks/VulkanFramework.h>
#include <AssetsEngine/AssetsEngine.h>
#include <ScriptingEngine/ScriptingEngine.h>

int Application::Init(Ref<ApplicationInfo> info)
{
    LP_CORE_INFO("Starting LowpEngine on version 1.0.0");
    app_info = info;
    StartAssetsEngine(info);
    ScriptingEngine::InitMono(info);
    CreateAppWindow(info->GetWindowCreateInfo());

    return LowpResultCodes::Success;
}

void Application::Run()
{
   
    while (!GetWindow()->ShouldClose())
    {
        window_data->created_window->ProcessEvents();
        window_data->event_buss->ResolveQue();
        ((Framework*)window_data->created_rendering_framework)->Tick();
        ((Framework*)window_data->created_rendering_framework)->SwapWindow();
    }
}

int Application::CreateAppWindow(Ref<WindowCreateInfo> info)
{
    Ref<AppWindow> app_window = CreateRef<AppWindow>();
    Ref<Window> created_window = CreateRef<Window>();

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

    ((Framework*)app_window->created_rendering_framework)->OnSdlSetup();
    if (created_window->Init(info) != LowpResultCodes::Success)
    {
        LP_CORE_ERROR("Window initiation failed");
        return LowpResultCodes::UnknowError;
    }

    LP_CORE_INFO("Opening window");
    ((Framework*)app_window->created_rendering_framework)->Init(app_info, created_window->getSdlWindow());

    app_window->event_buss = CreateRef<EventBus>();

    created_window->ShowWindow();
    app_window->created_window = created_window;
    window_data = app_window;
    return LowpResultCodes::Success;
}

void Application::CleanUp()
{
    LP_CORE_INFO("Closing engine");
    ((Framework*)window_data->created_rendering_framework)->Cleanup();
    window_data->created_window->CleanUp();
    ScriptingEngine::ShutdownMono();
}
