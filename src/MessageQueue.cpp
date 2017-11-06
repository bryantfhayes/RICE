#include "MessageQueue.h"

Msg* CreateNewMessage(MsgType type, const char* data)
{
	Msg* msg = (Msg*) malloc(sizeof(Msg));
	msg->type = type;
	if (data != NULL)
	{
		strncpy(msg->data, data, MAX_MSG_STRING_LENGTH);
	}
	msg->next = NULL;
	return msg;
}

MessageQueue::MessageQueue() :
head(NULL),
tail(NULL),
mCount(0)
{
  printf("New message queue made!\n");
}

Msg* MessageQueue::pop()
{
	if (head == NULL)
	{
		return NULL;
	}

	mCount--;

	Msg* temp = head;
	head = head->next;
	return temp;
}

csys_status MessageQueue::push(Msg* msg)
{
	csys_status status = csys_status_success;

	if (msg == NULL)
	{
		cm_status_returnError(status, csys_err_nullParam);
	}

	mCount++;

	if (tail == NULL)
	{
		tail = msg;
	}
	else
	{
		tail->next = msg;
		tail = msg;
	}

	if (head == NULL)
	{
		head = tail;
	}

	cm_status_return(status);
}

int MessageQueue::count()
{
	return mCount;
}
