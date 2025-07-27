#ifndef ALLMINIONBUFF_H
#define ALLMINIONBUFF_H

#include "ability.h"
#include "../game.h"
#include "../player.h"
#include "../card.h"
#include "../actions/action.h"
#include "../lib.h"

class AllMinionBuff: public Ability {
  int atkBuff;
  int defBuff;
  void execute(Game& game, Card* card, Action* action) override {
    for (auto m: game.getActivePlayer().getBoard().getMinions()) {
      std::cout << "buffing minion" << std::endl;
      m->setAtk(m->getAtk() + atkBuff);
      m->setDef(m->getDef() + defBuff);
    }
  };

  public:
    AllMinionBuff(int atkBuff, int defBuff): atkBuff(atkBuff), defBuff(defBuff) {};
};


#endif // ALLMINIONSTATCHANGE_H