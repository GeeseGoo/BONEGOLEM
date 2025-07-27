#ifndef STARTTURN_H
#define STARTTURN_H

#include "action.h"
class Game;

class StartTurn: public Action {
  public:
  StartTurn() {}
  void execute(Game &game) override;
};


#endif // STARTTURN_H