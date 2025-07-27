#include "endTurn.h"
#include "../game.h"

void EndTurn::execute(Game &game) {
for (auto trigger: game.getTriggers()) {
    trigger->beTriggered(this, game); 
}
}
