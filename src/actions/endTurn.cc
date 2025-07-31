#include "endTurn.h"
#include "../game.h"
#include "../lib.h"

void EndTurn::execute(Game &game) {
    playerNum = game.getPlayerNum();
    // std::cout << "NOT notifying end turn game triggers" << std::endl;
}

bool EndTurn::checkTrigger(Trigger* trig, Board &board, Game &game){
    return trig->beTriggered(this, board, game);
}

