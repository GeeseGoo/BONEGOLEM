#ifndef MINIONCREATE_H
#define MINIONCREATE_H

#include "action.h"
#include "../lib.h"
#include "../card.h"

class Game;

// creates a new minion on the board (that was not previously in existence)
class MinionCreate : public Action {
  std::string name;
  int player;
  Card* entering = nullptr;

public:
  MinionCreate(std::string name, int player) : name(name), player{player} {}
  void execute(Game &game) override;
  int getPlayer() const;
  bool checkTrigger(Trigger* trig, Board &board, Game &game) override;
};

#endif // ENTERPLAY_H