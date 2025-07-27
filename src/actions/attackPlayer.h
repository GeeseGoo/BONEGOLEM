#ifndef ATTACKPLAYER_H
#define ATTACKPLAYER_H

#include "action.h"
#include "../game.h"
class AttackPlayer: public Action {

  int attackerID;
  public:
    AttackPlayer(int attackerID): attackerID(attackerID) {}
    void execute(Game& game);
};

#endif // ATTACKPLAYER_H