#include "useability.h"
#include "../game.h"
#include "../globals.h"

void UseAbility::execute(Game &game) {
    validUse = false;
    cout << "executing ability use for " << cardID << endl;
    // code for checking and lowering player magic
    int oldMagic = game.getPlayers().at(player).getMagic();
    if(!game.getPlayers().at(player).deltaMagic(game.getActivePlayer().getBoard().getMinion(cardID)->getAbilityCost())){
        return;
    }
    
    if (!game.getPlayers().at(player).getBoard().getMinion(cardID)->deltaActions(1)){
        game.getPlayers().at(player).setMagic(oldMagic);
        return;
    }

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

void UseAbility::act(Game& game) {
    execute(game);
    if(validUse) game.trigger(this);
}
