#include "BHEngine.h"

BHEngine::BHEngine() {
  printf("New engine made!\n");
}

csys_status BHEngine::init() {
  printf("Initializing game engine...\n");

  // TEST CODE!

  // Create and post message
  Msg* msg = CreateNewMessage(eMsgType_Misc, "hello world!\n");
  MessageBus* messageBus = new MessageBus;
  messageBus->postMessage(msg);

  // Pop off head message and read it
  Msg* poppedMsg = messageBus->getFirstMessage();
  if (poppedMsg != NULL)
  {
    printf("%s\n", poppedMsg->data);
  }
  else
  {
    printf("No data!\n");
  }

  return csys_status_success;
}

csys_status BHEngine::run() {
  csys_status status = csys_status_success;

  printf("Running game engine...\n");

  int playerx=40,playery=25;
  TCODConsole::initRoot(80,50,"libtcod C++ tutorial",false);
  while ( !TCODConsole::isWindowClosed() ) {
    TCOD_key_t key;
    TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS,&key,NULL);
    switch(key.vk) {
      case TCODK_UP : playery--; break;
      case TCODK_DOWN : playery++; break;
      case TCODK_LEFT : playerx--; break;
      case TCODK_RIGHT : playerx++; break;
      default:break;
    }
    TCODConsole::root->clear();
    TCODConsole::root->putChar(playerx,playery,'@');
    TCODConsole::flush();
  }

  cm_status_return(status);
}