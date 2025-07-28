#ifndef LEAVEPLAY_H
#define LEAVEPLAY_H

#include "action.h"
#include "../lib.h"
#include "../minions/minion.h"
#include "../board.h"

class Game;

class LeavePlay : public Action
{

  Minion &minion;
  Board &board;

public:
  LeavePlay(Minion &minion, Board &board) : minion(minion), board(board) {}
  void execute(Game &game)
  {
    game.getActivePlayer().getBoard().notifyLeavePlayTriggers(this, game.getActivePlayer().getBoard(), game);
    game.getInactivePlayer().getBoard().notifyLeavePlayTriggers(this, game.getActivePlayer().getBoard(), game);
    std::cout << "removing minion from board: " << minion.getName() << std::endl;
    board.removeMinion(minion);
  }
};

#endif // LEAVEPLAY_H