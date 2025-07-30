#ifndef DESTROY_H
#define DESTROY_H

#include "ability.h"
#include "../game.h"
#include "../player.h"
#include "../card.h"
#include "../actions/action.h"
#include "../lib.h"
#include "../actions/enterplay.h"
#include "../actions/expireritual.h"

// destroys a specific minion/ritual (use onto=-1 for ritual)
class Destroy : public Ability {
    int playerNum;
    int minionIdx;
    void execute(Game &game, Card *card, Action *action, int player, int onto) override {
        if(onto >= 0){
            Minion& triggeringCard = *game.getPlayers().at(playerNum).getBoard().getMinion(minionIdx);
            game.action(make_unique<KillMinion>(triggeringCard, game.getPlayers().at(playerNum)));
        }else{
            game.action(make_unique<ExpireRitual>(playerNum));
        }
    };
  public:
    Destroy(int playerNum, int minionIdx) : playerNum{playerNum}, minionIdx{minionIdx} {};
};

#endif // DESTROY_H