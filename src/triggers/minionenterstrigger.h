#ifndef MINIONENTERTRIGGER_H
#define MINIONENTERTRIGGER_H

#include "../actions/enterplay.h"
#include "trigger.h"
#include "../game.h"

class MinionEntersTrigger : public Trigger
{

public:
  MinionEntersTrigger(std::unique_ptr<Ability> &&ability, Card *card) : Trigger(std::move(ability), card) {};
  void beTriggered(EnterPlay *action, Board &board, Game &game) override
  {
    std::cout << "minion enter triggered" << std::endl;
    ability->activate(game, card, action);
  };
};

#endif // MINIONENTERTRIGGER_H