#ifndef STARTTURN_H
#define STARTTURN_H

#include "action.h"
#include "../deck.h"
#include "../game.h"
class StartTurn: public Action {

  public:
  StartTurn() {}
  void execute(Game &game) override {
    Player &playerRef = game.getActivePlayer();
    if (!playerRef.isHandFull()) {
      playerRef.draw();
    }
    game.nextPlayer();
  };
};


#endif // STARTTURN_H