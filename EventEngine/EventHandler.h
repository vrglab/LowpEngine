/* ======================================================================================== */
/* LowpEngine - Event Engine C/C++ header file.												*/
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>

class EventHandler {
private:
    std::vector<std::function<void()>> listeners;

public:
    EventHandler();

    void Dispatch();
    void AddListener(const std::function<void()>& e);
};