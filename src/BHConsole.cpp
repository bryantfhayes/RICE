#include "BHConsole.h"

BHConsole::BHConsole() {
  printf("New console made!\n");
}

csys_status BHConsole::handleMessage(Msg* msg) {
  printf("%s\n", msg->data);
  return csys_status_success;
}