/* ======================================================================================== */
/* LowpEngine - Core C/C++ header file.														*/
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>
#include "Event.h"
#include "Events/WindowEvents.h"

class EventHandlerBase {
public:
    virtual ~EventHandlerBase() {}
    virtual void Dispatch() = 0;
};

template<typename T>
class EventHandler : public EventHandlerBase {
private:
    Event& m_Event;
    std::vector<std::function<void(T&)>> listeners;

public:
    EventHandler(Event& event);

    void Dispatch() override;
    void AddListener(const std::function<void(T&)>& e);
};

template class EventHandler<E_WindowResize>;