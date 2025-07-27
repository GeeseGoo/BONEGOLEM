#include "attackMinion.h"
#include "../game.h"

void AttackMinion::execute(Game& game) {
    Minion* attacker = game.getActivePlayer().getBoard().getMinion(attackerID);
    attacker->attack(*game.getInactivePlayer().getBoard().getMinion(attackeeID));
};
