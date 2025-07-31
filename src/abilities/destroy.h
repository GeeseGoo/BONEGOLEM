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
class Destroy : public Ability
{
    void execute(Game &game, Card *card, Action *action, int player, int onto) override
    {
        if (onto >= 0)
        {
            Minion &triggeringCard = *game.getPlayers().at(player).getBoard().getMinion(onto);
            game.action(make_unique<KillMinion>(triggeringCard, game.getPlayers().at(player)));
        }
        else
        {
            game.action(make_unique<ExpireRitual>(player));
        }
    };

public:
    Destroy() {};
};

#endif // DESTROY_H