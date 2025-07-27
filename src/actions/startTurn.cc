#include "startTurn.h"
#include "../game.h"

void StartTurn::execute(Game &game) {
game.nextPlayer();
Player &playerRef = game.getActivePlayer();
if (!playerRef.isHandFull()) {
    playerRef.draw();
}
};
