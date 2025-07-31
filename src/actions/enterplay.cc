#include "enterplay.h"
#include "../game.h"

void EnterPlay::execute(Game &game)
{
    auto &player = game.getActivePlayer();
    auto &hand = player.getHand();
    if (!player.deltaMagic(hand.getCard(cardID).getCost()))
        return;
    auto card = hand.extractCard(cardID).release();
    card->play(game, player, this);
    // std::cout << "played card " << std::to_string(cardID) << std::endl;
}

int EnterPlay::getOnto() const
{
    return onto;
}

int EnterPlay::getPlayer() const
{
    return player;
}

bool EnterPlay::checkTrigger(Trigger *trig, Board &board, Game &game)
{
    return trig->beTriggered(this, board, game);
}
