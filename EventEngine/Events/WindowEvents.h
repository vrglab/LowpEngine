/* ======================================================================================== */
/* LowpEngine - Core C/C++ header file.														*/
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>
#include "EventEngine/Event.h"

LP_Export enum WindowEventType
{
	resize = 0
};


LP_Export class E_WindowResize: public Event
{
public:
	EVENT_CLASS_TYPE(WindowEventType::resize)
	EVENT_CLASS_CATEGORY(BIT(0))
};