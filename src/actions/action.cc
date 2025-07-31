#include "action.h"
#include "../game.h"

void Action::act(Game& game) {
    execute(game);
    game.trigger(this);
}
