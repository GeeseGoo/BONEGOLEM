#ifndef ENTERING_MINION_BUFF_H
#define ENTERING_MINION_BUFF_H

#include "ability.h"
#include "../game.h"
#include "../player.h"
#include "../card.h"
#include "../actions/action.h"
#include "../lib.h"
#include "../actions/enterplay.h"

class EnteringMinionBuff : public Ability
{
    int atkBuff;
    int defBuff;

    // SHOULD ONLY BE CALLED ON EnterPlay ACTIONS !
    void execute(Game &game, Card *card, Action *action) override {
      Minion* enteringCard = dynamic_cast<Minion*>(dynamic_cast<EnterPlay*>(action)->getCard());
      enteringCard->setAtk(enteringCard->getAtk() + atkBuff);
      enteringCard->takeDamage(-1 * defBuff);
    };
  public:
    EnteringMinionBuff(int atkBuff, int defBuff) : atkBuff(atkBuff), defBuff(defBuff) {};
};

#endif // ENTERING_MINION_BUFF_H