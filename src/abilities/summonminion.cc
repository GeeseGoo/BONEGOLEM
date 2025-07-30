#include "summonminion.h"
#include "../createCard.h"

void SummonMinion::execute(Game &game, Card *card, Action *action, int player, int onto) {
    for(int i = 0; i < number; i++){
        game.getPlayers().at(player).getBoard().addCard(dynamic_cast<Minion*>(::createCard(minionName, player).release()));
    }
};
