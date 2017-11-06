#ifndef MESSAGEQUEUE_11032017
#define MESSAGEQUEUE_11032017

#include "Status.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#define MAX_MSG_STRING_LENGTH 255

typedef enum MsgType {
	eMsgType_Misc = 0
} MsgType;

typedef struct Msg Msg;
typedef struct Msg {
	char data[MAX_MSG_STRING_LENGTH];
	MsgType type;
	Msg* next;
} Msg;

/**
 * @brief Helper for creating a new message.
 */
Msg* CreateNewMessage(MsgType type, const char* data);

class MessageQueue {
  public:
    MessageQueue();
    Msg* pop();
    csys_status push(Msg* msg);
    int count();
  private:
  	Msg* head;
  	Msg* tail;
  	int mCount;
};

#endif