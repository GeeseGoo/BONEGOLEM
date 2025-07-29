#include "enterplay.h"
#include "../game.h"

void EnterPlay::execute(Game &game)
{
    auto &player = game.getActivePlayer();
    auto &hand = player.getHand();
    auto card = hand.extractCard(cardID).release();
    card->play(game, player, this);
    std::cout << "played card" << std::to_string(cardID) << std::endl;
}

int EnterPlay::getOnto() const {
    return onto;
}

int EnterPlay::getPlayer() const {
    return player;
}

  void EnterPlay::checkTrigger(Trigger* trig, Board &board, Game &game){
    trig->beTriggered(this, board, game);
  }

