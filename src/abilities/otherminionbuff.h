#ifndef ENTERING_MINION_BUFF_H
#define ENTERING_MINION_BUFF_H

#include "ability.h"
#include "../game.h"
#include "../player.h"
#include "../card.h"
#include "../actions/action.h"
#include "../lib.h"
#include "../actions/enterplay.h"

// For buffing a minion that does the triggering
// eg buff any minion that enters the board
// would apply to the third number for a "use" of an activated ability
class OtherMinionBuff : public Ability
{
    int atkBuff;
    int defBuff;

    void execute(Game &game, Card *card, Action *action, int player, int onto) override {
      if(onto >= 0){
        Minion* triggeringCard = game.getPlayers().at(player).getBoard().getMinion(onto);
        triggeringCard->setAtk(triggeringCard->getAtk() + atkBuff);
        triggeringCard->takeDamage(-1 * defBuff);
      }
      else{
        // apply to ritual?
      }
    }
  public:
    OtherMinionBuff(int atkBuff, int defBuff) : atkBuff(atkBuff), defBuff(defBuff) {};
};

#endif // ENTERING_MINION_BUFF_H