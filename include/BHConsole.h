#ifndef BHCONSOLE_11032017
#define BHCONSOLE_11032017

#include "System.h"

class BHConsole : System {
  public:
    BHConsole();
    /* override */ csys_status handleMessage(Msg* msg);
  private:
    MessageBus* msgBus;
};

#endif