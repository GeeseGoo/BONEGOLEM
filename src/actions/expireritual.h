#ifndef EXPIRERITUAL_H
#define EXPIRERITUAL_H

#include "action.h"
#include "../lib.h"
#include "../minions/minion.h"
#include "../board.h"

class Game;

// for removing a ritual from the board
class ExpireRitual : public Action
{
  int playerNum;

public:
  ExpireRitual(int playerNum) : playerNum{playerNum} {}
  void execute(Game &game);
  bool checkTrigger(Trigger *trig, Board &board, Game &game) override;
};

#endif // EXPIRERITUAL_H