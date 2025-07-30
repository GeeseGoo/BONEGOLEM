#include "killminion.h"
#include "leaveplay.h"
#include "../game.h"
#include "../graveyard.h"

void KillMinion::execute(Game &game){
    game.action(make_unique<LeavePlay>(minion, player.getBoard()));
    player.getGraveyard().add(&minion);
}

bool KillMinion::checkTrigger(Trigger* trig, Board &board, Game &game){
    return trig->beTriggered(this, board, game);
}