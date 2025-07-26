#ifndef ATTACKPLAYER_H
#define ATTACKPLAYER_H

#include "action.h"
#include "../game.h"
#include "../minions/minion.h"
class AttackPlayer: public Action {

  int attackerID;
  public:
    AttackPlayer(int attackerID): attackerID(attackerID) {}
    void execute(Game& game) {
      Minion& attacker = game.getActivePlayer().getBoard().getMinion(attackerID);
      attacker.attack(game.getInactivePlayer());
    };
};

#endif // ATTACKPLAYER_H