#ifndef STARTTURN_H
#define STARTTURN_H

#include "action.h"
#include "../deck.h"
#include "../game.h"
class StartTurn: public Action {

  public:
  StartTurn() {}
  void execute(Game &game) override {
    game.nextPlayer();
    Player &playerRef = game.getActivePlayer();
    if (!playerRef.isHandFull()) {
      playerRef.draw();
    }
  };
};


#endif // STARTTURN_H