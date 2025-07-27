#include "attackPlayer.h"
#include "../game.h"

void AttackPlayer::execute(Game& game) {
    Minion* attacker = game.getActivePlayer().getBoard().getMinion(attackerID);
    attacker->attack(game.getInactivePlayer());
};
