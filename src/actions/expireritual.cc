#include "expireritual.h"
#include "../game.h"
#include "../triggers/trigger.h"


void ExpireRitual::execute(Game &game)
{
    std::cout << "removing ritual from board of player " << playerNum << std::endl;
    game.getBoards().at(playerNum)->removeRitual();
}

bool ExpireRitual::checkTrigger(Trigger *trig, Board &board, Game &game)
{
    return trig->beTriggered(this, board, game);
}

