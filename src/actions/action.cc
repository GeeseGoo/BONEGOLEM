#include "action.h"
#include "../game.h"

void Action::act(Game& game) {
    game.trigger(this);
    execute(game);
}
