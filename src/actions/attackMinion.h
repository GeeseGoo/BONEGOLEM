#ifndef ATTACKMINION_H
#define ATTACKMINION_H

#include "action.h"
#include "../game.h"

class AttackMinion: public Action {

  int attackerID;
  int attackeeID;
  public:
    AttackMinion(int attackerID, int attackeeID): attackerID(attackerID), attackeeID(attackeeID) {}
    void execute(Game& game);
};

#endif // ATTACKMINION_H