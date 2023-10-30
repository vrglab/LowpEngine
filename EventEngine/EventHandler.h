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

class EventHandlerBase
{
public:
    virtual ~EventHandlerBase() {}

    // This is a pure virtual function for dispatching the event.
    virtual void Dispatch() = 0;
};

typedef bool event_function(Event& event);

template<typename T>
class EventHandler : public EventHandlerBase
{
public:
    EventHandler(Event& event)
        : m_Event(event)
    {
    }
    void Dispatch() override;
    void AddListener(const event_function& e);

private:
    Event& m_Event;
    std::vector<event_function*> listeners;
};