#include "minioncreate.h"
#include "../game.h"
#include "../createCard.h"

void MinionCreate::execute(Game &game) {
    game.getPlayers().at(player).getBoard().addCard(dynamic_cast<Minion*>(::createCard(name, player).release()));
}

void MinionCreate::checkTrigger(Trigger* trig, Board &board, Game &game){
  trig->beTriggered(this, board, game);
}

int MinionCreate::getPlayer() const{
    return player;
}