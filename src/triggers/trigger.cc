#include "trigger.h"
#include "../actions/action.h"

bool Trigger::trigger(Action *action, Board &board, Game &game){
    return action->checkTrigger(this, board, game);
}

Trigger::~Trigger() = default;

