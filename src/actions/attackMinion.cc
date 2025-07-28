#include "attackMinion.h"
#include "../game.h"

void AttackMinion::execute(Game &game)
{
    Minion *attacker = game.getActivePlayer().getBoard().getMinion(attackerID);
    game.takeDamage(*game.getInactivePlayer().getBoard().getMinion(attackeeID), game.getInactivePlayer().getBoard(), attacker->getAtk());
};
