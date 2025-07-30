#include "startTurn.h"
#include "../game.h"
#include "../lib.h"

void StartTurn::execute(Game &game)
{
    game.nextPlayer();
    playerNum = game.getPlayerNum();
    Player &playerRef = game.getActivePlayer();
    // set all player's minions to one action
    for (auto m : playerRef.getBoard().getMinions())
    {
        m->setActions(1);
    }
    playerRef.deltaMagic(-1);
    if (!playerRef.isHandFull())
    {
        playerRef.draw();
    }
    std::cout << "NOT notifying start turn triggers" << std::endl;
};

bool StartTurn::checkTrigger(Trigger *trig, Board &board, Game &game)
{
    return trig->beTriggered(this, board, game);
}
