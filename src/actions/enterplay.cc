#include "enterplay.h"
#include "../game.h"

void EnterPlay::execute(Game &game)
{
    auto &player = game.getActivePlayer();
    auto &hand = player.getHand();
    auto card = hand.extractCard(cardID).release();
    card->play(game, player, this);
    std::cout << "played card" << std::to_string(cardID) << std::endl;
    game.getActivePlayer().getBoard().notifyEnterPlayTriggers(this, game.getActivePlayer().getBoard(), game);
    game.getInactivePlayer().getBoard().notifyEnterPlayTriggers(this, game.getActivePlayer().getBoard(), game);
}

int EnterPlay::getOnto() const {
    return onto;
}