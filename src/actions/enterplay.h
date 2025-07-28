#ifndef ENTERPLAY_H
#define ENTERPLAY_H

#include "action.h"
#include "../lib.h"

class Game;

class EnterPlay : public Action
{

  int cardID;

public:
  EnterPlay(int cardID) : cardID(cardID) {}
  void execute(Game &game);
};

#endif // ENTERPLAY_H