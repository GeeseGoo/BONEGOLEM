#include "minioncreate.h"
#include "../game.h"
#include "../createCard.h"

void MinionCreate::execute(Game &game) {
    game.getPlayers().at(player).getBoard().addCard(dynamic_cast<Minion*>(::createCard(name, player).release()));
}

bool MinionCreate::checkTrigger(Trigger* trig, Board &board, Game &game){
  return trig->beTriggered(this, board, game);
}

int MinionCreate::getPlayer() const{
    return player;
}