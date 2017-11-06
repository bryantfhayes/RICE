#include "MessageBus.h"

MessageBus::MessageBus() {
  printf("New message bus made!\n");
  messages = new MessageQueue;
}

csys_status MessageBus::postMessage(Msg* msg) {
	csys_status status = csys_status_success;

	status = messages->push(msg);
	cm_status_returnIfFailed(status);

	cm_status_return(status);
}

Msg* MessageBus::getFirstMessage()
{
	return messages->pop();
}