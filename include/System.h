#ifndef SYSTEM_11032017
#define SYSTEM_11032017

#include "libtcod.hpp"
#include "Status.h"
#include "MessageBus.h"

class System {
	public:
		virtual csys_status handleMessage(Msg* msg) = 0;
	private:
		MessageBus* msgBus;
};

#endif