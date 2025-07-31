#include "leaveplay.h"
#include "../game.h"

void LeavePlay::act(Game& game) {
    game.trigger(this);
    execute(game);
}
