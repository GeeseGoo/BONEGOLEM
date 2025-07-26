#ifndef ATTACKMINION_H
#define ATTACKMINION_H

#include "action.h"
#include "../game.h"
#include "../minions/minion.h"
class AttackMinion: public Action {

  int attackerID;
  int attackeeID;
  public:
    AttackMinion(int attackerID, int attackeeID): attackerID(attackerID), attackeeID(attackeeID) {}
    void execute(Game& game) {
      Minion* attacker = game.getActivePlayer().getBoard().getMinion(attackerID);
      attacker->attack(*game.getInactivePlayer().getBoard().getMinion(attackeeID));
    };
};

#endif // ATTACKMINION_H