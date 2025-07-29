#include "useability.h"
#include "../game.h"

void UseAbility::execute(Game &game)
{
    // code for checking and lowering player magic
    validUse = true;
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

Card* UseAbility::getUser() const {
    return user;
}
