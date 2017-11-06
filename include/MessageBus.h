#ifndef MESSAGEBUS_11032017
#define MESSAGEBUS_11032017

#include "MessageQueue.h"

class MessageBus {
  public:
    MessageBus();
    csys_status postMessage(Msg* msg);
    Msg* getFirstMessage();
  private:
  	MessageQueue* messages;
};

#endif