#ifndef ENDTURN_H
#define ENDTURN_H

#include "action.h"
class Game;

class EndTurn: public Action {
  int playerNum;

  public:

  EndTurn() {}
  void execute(Game &game) override;
};


#endif