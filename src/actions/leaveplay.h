#ifndef LEAVEPLAY_H
#define LEAVEPLAY_H

#include "action.h"
#include "../lib.h"
#include "../minions/minion.h"
#include "../board.h"

class Game;

// this gets created by the KillMinion command, but should be used whenever a minion leaves the board (even if it isn't dead)
class LeavePlay : public Action
{
  Minion &minion;
  Board &board;

public:
  LeavePlay(Minion &minion, Board &board) : minion(minion), board(board) {}
  void execute(Game &game)
  {
    std::cout << "removing minion from board: " << minion.getName() << std::endl;
    board.removeMinion(minion);
  }
  bool checkTrigger(Trigger *trig, Board &board, Game &game) override
  {
    return trig->beTriggered(this, board, game);
  }
  void act(Game& game) override;
};

#endif // LEAVEPLAY_H