#ifndef MINIONLEAVESTRIGGER_H
#define MINIONLEAVESTRIGGER_H

#include "../actions/leaveplay.h"
#include "trigger.h"
#include "../game.h"

class MinionLeavesTrigger : public Trigger {
public:
  MinionLeavesTrigger(std::unique_ptr<Ability> &&ability, Card *card) : Trigger(std::move(ability), card) {};
  bool beTriggered(LeavePlay *action, Board &board, Game &game) override {
    // std::cout << "minion leave triggered" << std::endl;
    ability->activate(game, card, action, -1,-1);
    return true;
  }
};

#endif // MINIONLEAVESTRIGGER_H