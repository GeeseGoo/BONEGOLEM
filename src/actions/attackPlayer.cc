#include "attackPlayer.h"
#include "../game.h"

void AttackPlayer::execute(Game &game)
{
    Minion *attacker = game.getActivePlayer().getBoard().getMinion(attackerID);
    if (!attacker->deltaActions(1))
        return;
    attacker->attack(game.getInactivePlayer());
};
