#include "useability.h"
#include "../game.h"

void UseAbility::execute(Game &game)
{
    Player &player = game.getActivePlayer();
    Board &board = player.getBoard();
    user = board.getMinion(cardID);
}

int UseAbility::getOnto() const {
    return onto;
}

int UseAbility::getPlayer() const {
    return player;
}
void UseAbility::checkTrigger(Trigger* trig, Board &board, Game &game){
trig->beTriggered(this, board, game);
}
