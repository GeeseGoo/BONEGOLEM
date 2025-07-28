#include "startTurn.h"
#include "../game.h"
#include "../lib.h"

void StartTurn::execute(Game &game) {
game.nextPlayer();
playerNum = game.getPlayerNum();
Player &playerRef = game.getActivePlayer();
if (!playerRef.isHandFull()) {
    playerRef.draw();
}
std::cout << "notifying start turn triggers" << std::endl;
game.getActivePlayer().getBoard().notifyStartTurnTriggers(this, game.getActivePlayer().getBoard(), game);

};
