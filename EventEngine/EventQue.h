/* ======================================================================================== */
/* LowpEngine - Core C/C++ header file.														*/
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <map>
#include <EngineCommons/EngineCommons.h>
#include "Event.h"


LP_Export class EventQue
{
private:
	std::vector<Ref<Event>> m_EventQueue;
	std::map<int, std::vector<std::function<void(Ref<Event>)>>> eventListeners_;
public:
	void Enqueue(Ref<Event> event);
	void AddListener(int eventType, const std::function<void(Ref<Event>)>& listener);
	void DispatchEvents();
	static EventQue& GetInstance() {
		static EventQue instance; 
		return instance;
	}
};