#include "summonminion.h"
#include "../createCard.h"
#include "../actions/minioncreate.h"

void SummonMinion::execute(Game &game, Card *card, Action *action, int player, int onto) {
    for(int i = 0; i < number; i++){
        game.action(make_unique<MinionCreate>(minionName, player));
    }
};
