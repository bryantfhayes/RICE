#ifndef BHENGINE_11032017
#define BHENGINE_11032017

#include "libtcod.hpp"
#include "Status.h"
#include "MessageBus.h"

class BHEngine {
	public:
		BHEngine();
		csys_status run();
		csys_status init();
};

#endif