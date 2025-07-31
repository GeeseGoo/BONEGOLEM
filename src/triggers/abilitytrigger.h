#ifndef ABILITYTRIGGER_H
#define ABILITYTRIGGER_H

#include "trigger.h"
#include "../actions/useability.h"

// Trigger goes on minions with activated abilities -> activated by the 'use' command
class AbilityTrigger : public Trigger {
public:
  AbilityTrigger(std::unique_ptr<Ability> &&ability, Card *card) : Trigger(std::move(ability), card) {};
  bool beTriggered(UseAbility *action, Board &board, Game &game) override
  {
    if(action->getUser() == card){
      // std::cout << "ability triggered" << std::endl;
      ability->activate(game, card, action, action->getPlayer(), action->getOnto());
      return true;
    }
    return false;
  };
};

#endif // ABILITYTRIGGER_H