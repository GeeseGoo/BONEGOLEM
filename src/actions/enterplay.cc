#include "enterplay.h"
#include "../game.h"

void EnterPlay::execute(Game &game)
{
    auto &player = game.getActivePlayer();
    auto &hand = player.getHand();
    auto card = hand.extractCard(cardID);
    card->play(game, std::move(card), player);
    game.getActivePlayer().getBoard().notifyEnterPlayTriggers(this, game.getActivePlayer().getBoard(), game);
    game.getInactivePlayer().getBoard().notifyEnterPlayTriggers(this, game.getActivePlayer().getBoard(), game);

    std::cout << "played card" << std::to_string(cardID) << std::endl;
};
