#ifndef MINIONENTERTRIGGER_H
#define MINIONENTERTRIGGER_H

#include "../actions/enterplay.h"
#include "../actions/minioncreate.h"
#include "trigger.h"
#include "../game.h"

class MinionEntersTrigger : public Trigger {
  int exempt;
public:
  MinionEntersTrigger(std::unique_ptr<Ability> &&ability, Card *card, int exemption = -1) : Trigger(std::move(ability), card), exempt{exemption} {};
  bool beTriggered(EnterPlay *action, Board &board, Game &game) override {
    if(!action->isMinion() || action->getPlayer() == exempt){
      return false;
    }
    std::cout << "minion enter triggered" << std::endl;
    ability->activate(game, card, action, action->getPlayer(), game.getPlayers().at(action->getPlayer()).getBoard().getMinions().size()-1);
    return true;
  }
  bool beTriggered(MinionCreate *action, Board &board, Game &game) override {
    if(action->getPlayer() == exempt){
      return false;
    }
    std::cout << "minion enter triggered" << std::endl;
    ability->activate(game, card, action, action->getPlayer(), game.getPlayers().at(action->getPlayer()).getBoard().getMinions().size()-1);
    return true;
  }
};

#endif // MINIONENTERTRIGGER_H