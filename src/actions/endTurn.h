#ifndef ENDTURN_H
#define ENDTURN_H

#include "action.h"

class EndTurn: public Action {
  int playerNum;

  public:

  int getPlayerNum() { return playerNum;};
  void execute(Game &game) override;
  void checkTrigger(Trigger* trig, Board &board, Game &game) override;
};


#endif