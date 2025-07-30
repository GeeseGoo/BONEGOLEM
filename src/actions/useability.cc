#include "useability.h"
#include "../game.h"

void UseAbility::execute(Game &game)
{
    // code for checking and lowering player magic
    if (!game.getPlayers().at(player).deltaMagic(game.getActivePlayer().getBoard().getMinion(cardID)->getAbilityCost()))
        return;
    validUse = true;
    user = game.getPlayers().at(player).getBoard().getMinion(cardID);
}

int UseAbility::getOnto() const
{
    return onto;
}

int UseAbility::getPlayer() const
{
    return player;
}
bool UseAbility::checkTrigger(Trigger *trig, Board &board, Game &game)
{
    return trig->beTriggered(this, board, game);
}

Card *UseAbility::getUser() const
{
    return user;
}
