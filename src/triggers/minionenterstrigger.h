#ifndef MINIONENTERTRIGGER_H
#define MINIONENTERTRIGGER_H

#include "../actions/enterplay.h"
#include "trigger.h"
#include "../game.h"

class MinionEntersTrigger : public Trigger
{
  Player* exempt;
public:
  MinionEntersTrigger(std::unique_ptr<Ability> &&ability, Card *card, Player* exemption = nullptr) : Trigger(std::move(ability), card), exempt{exemption} {};
  void beTriggered(EnterPlay *action, Board &board, Game &game) override
  {
    if(!action->isMinion() || &game.getActivePlayer() == exempt){
      return;
    }
    std::cout << "minion enter triggered" << std::endl;
    ability->activate(game, card, action, action->getPlayer(), action->getOnto());
  };
};

#endif // MINIONENTERTRIGGER_H