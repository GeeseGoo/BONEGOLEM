#ifndef ENTERING_MINION_BUFF_H
#define ENTERING_MINION_BUFF_H

#include "ability.h"
#include "../game.h"
#include "../player.h"
#include "../card.h"
#include "../actions/action.h"
#include "../lib.h"
#include "../actions/enterplay.h"
#include "../actions/expireritual.h"

// For buffing a minion that does the triggering
// eg buff any minion that enters the board
class Destroy : public Ability
{
    void execute(Game &game, Card *card, Action *action, int player, int onto) override {
        if(onto > 0){
            Minion* triggeringCard = game.getPlayers().at(player).getBoard().getMinion(onto);
            game.action(make_unique<KillMinion>(triggeringCard, game.getPlayers().at(player)));
        }else{
            game.action(make_unique<ExpireRitual>(player));
        }
    };
  public:
    Destroy(int atkBuff, int defBuff);
};

#endif // ENTERING_MINION_BUFF_H