#ifndef ABILITYTRIGGER_H
#define ABILITYTRIGGER_H

#include "trigger.h"
class AbilityTrigger : public Trigger
{
public:
  AbilityTrigger(std::unique_ptr<Ability> &&ability, Card *card) : Trigger(std::move(ability), card) {};
  void beTriggered(Action *action, Board &board, Game &game) override
  {
    std::cout << "end turn triggered" << std::endl;
    ability->activate(game, card, action);
  };
};

#endif // ABILITYTRIGGER_H