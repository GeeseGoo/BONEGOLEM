#ifndef KILLMINION_H
#define KILLMINION_H

#include "action.h"
#include "../lib.h"
#include "../minions/minion.h"
#include "../board.h"

class Game;
class Minion;
class KillMinion : public Action {

  Minion &minion;
  Player &player;
public:
  KillMinion(Minion &minion, Player &player, bool toHand = false) : minion(minion), player(player) {}
  void execute(Game &game);
  bool checkTrigger(Trigger* trig, Board &board, Game &game) override;
};

#endif // KILLMINION_H