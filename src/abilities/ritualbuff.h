#ifndef RITUAL_BUFF_H
#define RITUAL_BUFF_H

#include "ability.h"
#include "../game.h"
#include "../player.h"
#include "../card.h"
#include "../actions/action.h"
#include "../lib.h"

class RitualBuff : public Ability
{
    int playerNum;
    int chargeIncrease;

    void execute(Game &game, Card *card, Action *action, int player, int onto) override {
        Ritual* ritual = game.getPlayers().at(playerNum).getBoard().getRitual();
        if(ritual) ritual->setCharges(ritual->getCharges()+chargeIncrease);
    }
  public:
    RitualBuff(int playerNum, int chargeIncrease) : playerNum(playerNum), chargeIncrease(chargeIncrease) {};
};

#endif // RITUAL_BUFF_H