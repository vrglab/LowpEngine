/* ======================================================================================== */
/* LowpEngine - Core C/C++ header file.														*/
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
	void QueHandler(void* event_handler);
	void ResolveQue();
	static EventBus& GetInstance() {
		static EventBus instance; // This instance is created once and only once
		return instance;
	}
private:
	std::vector<void*> qued_handlers;
};