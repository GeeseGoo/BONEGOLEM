#include "playcard.h"
#include "../game.h"

void PlayCard::execute(Game& game) {
    auto &player = game.getActivePlayer();
    auto &hand = player.getHand();
    auto card = hand.extractCard(cardID);
    card->play(game, std::move(card), player);
    std::cout << "played card" << std::to_string(cardID) << std::endl;
};
