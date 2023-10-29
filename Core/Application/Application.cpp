#include "pch.h"
#include "Application.h"
#include <EventEngine/EventEngine.h>

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

    return LowpResultCodes::Success;
}

void Application::Run()
{
    while (!created_window->ShouldClose()) 
    {
        created_window->ProcessEvents();
        EventQue::GetInstance().DispatchEvents();
    }
}

void Application::CleanUp()
{
    LP_CORE_INFO("Closing engine");
    created_window->CleanUp();
}
