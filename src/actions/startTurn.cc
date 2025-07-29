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
    std::cout << "NOT notifying start turn triggers" << std::endl;
};

void StartTurn::checkTrigger(Trigger* trig, Board &board, Game &game){
trig->beTriggered(this, board, game);
}

