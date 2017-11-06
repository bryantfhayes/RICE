#ifndef BHENGINE_11032017
#define BHENGINE_11032017

#include "libtcod.hpp"
#include "status.h"

class BHEngine {
	public:
		BHEngine();
		csys_status run();
		csys_status init();
};

#endif