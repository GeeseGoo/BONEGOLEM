#include "endTurn.h"
#include "../game.h"
#include "../lib.h"

void EndTurn::execute(Game &game) {
    playerNum = game.getPlayerNum();
    std::cout << "notifying end turn game triggers" << std::endl;
    game.notifyEndTurnTriggers(this);
}
