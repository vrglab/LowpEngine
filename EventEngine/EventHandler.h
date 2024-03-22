/* ======================================================================================== */
/* LowpEngine - Event Engine C/C++ header file.												*/
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>

/**
 * @brief This is the engines custom event in charge of
 */
class EventHandler {
private:
    std::vector<std::function<void()>> listeners;

public:
    EventHandler();

    /**
     * @brief Invokes all of the functions listed as a listener to us
     */
    void Dispatch();

    /**
     * @brief Add's a function to be invoked when the event is invoked
     * @param e The function to add to the list of functions
     */
    void AddListener(const std::function<void()>& e);
};