#ifndef ABILITYTRIGGER_H
#define ABILITYTRIGGER_H

#include "trigger.h"
#include "../actions/useability.h"

class AbilityTrigger : public Trigger
{
public:
  AbilityTrigger(std::unique_ptr<Ability> &&ability, Card *card) : Trigger(std::move(ability), card) {};
  void beTriggered(UseAbility *action, Board &board, Game &game) override
  {
    if(action->getUser() == card){
      std::cout << "ability triggered" << std::endl;
      ability->activate(game, card, action, action->getPlayer(), action->getOnto());
    }
  };
};

#endif // ABILITYTRIGGER_H