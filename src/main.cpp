#include "libtcod.hpp"
#include "BHEngine.h"

int main() {
	csys_status status = csys_status_success;

	BHEngine* engine = new BHEngine;
	
	status = engine->init();
	cm_status_returnIfFailed(status);

	status = engine->run();
	cm_status_returnIfFailed(status);

	return 0;
}