#ifndef BUFFME_H
#define BUFFME_H

#include "ability.h"
#include "../game.h"
#include "../card.h"
#include "../actions/action.h"
#include "../lib.h"

// For buffing a minion whenever it's trigger
class BuffMe : public Ability {
    int atkBuff;
    int defBuff;
    Minion* me;
    void execute(Game &game, Card *card, Action *action, int player, int onto) override {
      me->setAtk(me->getAtk() + atkBuff);
      me->takeDamage(-1 * defBuff);
    };
  public:
    BuffMe(int atkBuff, int defBuff, Minion* me) : atkBuff(atkBuff), defBuff(defBuff), me{me} {};
};

#endif // BUFFME_H