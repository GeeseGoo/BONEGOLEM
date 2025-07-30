#ifndef ATTACKMINION_H
#define ATTACKMINION_H

#include "action.h"
#include "../game.h"
#include "../triggers/trigger.h"

class AttackMinion: public Action {

  int attackerID;
  int attackeeID;
  public:
    AttackMinion(int attackerID, int attackeeID): attackerID(attackerID), attackeeID(attackeeID) {}
    void execute(Game& game);
    bool checkTrigger(Trigger* trig, Board &board, Game &game) override{
      return trig->beTriggered(this, board, game);
    }
};

#endif // ATTACKMINION_H