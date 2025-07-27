#ifndef PLAYCARD_h
#define PLAYCARD_h

#include "action.h"
#include "../lib.h"

class Game;

class PlayCard: public Action {

  int cardID;
  public:
    PlayCard(int cardID): cardID(cardID) {}
    void execute(Game& game);
};

#endif // PLAYCARD_h