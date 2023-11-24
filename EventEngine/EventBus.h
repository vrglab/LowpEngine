/* ======================================================================================== */
/* LowpEngine - Event Engine C/C++ header file.												*/
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>
#include "EventHandler.h"

LP_Export class EventBus
{
public:
	void QueHandler(Ref<EventHandler> event_handler);
	void ResolveQue();
private:
	std::vector<Ref<EventHandler>> qued_handlers;
};