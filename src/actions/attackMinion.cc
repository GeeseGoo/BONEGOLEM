#include "attackMinion.h"
#include "../game.h"

void AttackMinion::execute(Game &game)
{
    Minion *attacker = game.getActivePlayer().getBoard().getMinion(attackerID);
    if (!attacker->deltaActions(1))
        return;
    int damage = attacker->getAtk();
    std::cout << game.getInactivePlayer().getBoard().getMinion(attackeeID)->getName() << " was attacked by " << attacker->getName() << std::endl;
    attacker->takeDamage(damage);
    game.getInactivePlayer().getBoard().getMinion(attackeeID)->takeDamage(damage);
}
