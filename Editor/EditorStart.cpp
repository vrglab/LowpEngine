#include "pch.h"
#include <iostream>
#include <Core/LowpEngine.h>

#undef main

#ifdef _WIN32
#include <Windows.h>
int WINAPI main(int argc, char* argv[]) {

    /*LP_CORE_INFO("Starting Lowp Editor on version 1.0.0");
    Ref<Application> app = CreateRef<Application>();

    Ref<ApplicationInfo> info = ApplicationInfo::GetDefault();
    info->name = "Lowp Editor";

    app->app_info = info;
    app->CreateAppWindow(info->GetWindowCreateInfo());
    app->Run();
    app->CleanUp();*/

    std::vector<Scene> loaded_scenes = {};

    Scene scene = {};

    GameObject obj = {};
    obj.Name = "Loli";
    obj.guid = GUIDGen();
    Component transform = {};
    transform.engine_id = "Transform";
    obj.components.push_back(transform);

    Component testClass = {};
    testClass.engine_id = "TestClass";
    obj.components.push_back(testClass);
    scene.game_objects.push_back(obj);
    loaded_scenes.push_back(scene);
    GenerateSceneListFile("", loaded_scenes);

    return 0;
}

#elif defined(__linux__) || defined(__APPLE__)
int main(int argc, char* argv[]) {
    return 0;
}
#else
#error "Unsupported platform"
#endif