#include "trigger.h"
#include "../actions/action.h"

void Trigger::trigger(Action *action, Board &board, Game &game){
action->checkTrigger(this, board, game);
}
