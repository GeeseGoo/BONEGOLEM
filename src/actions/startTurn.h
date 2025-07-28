#ifndef STARTTURN_H
#define STARTTURN_H

#include "action.h"
class Game;

class StartTurn: public Action {
  int playerNum;
  public:
  StartTurn() {}
  void execute(Game &game) override;
  int getPlayerNum() {return playerNum;};
};


#endif // STARTTURN_H