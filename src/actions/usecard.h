#ifndef USEABILITY_H
#define USEABILITY_H

#include "action.h"
#include "../lib.h"
#include "../game.h"
#include "../abilities/ability.h"

class UseCard : public Action
{
  Ability *ability;

public:
  UseCard(Ability *ability) : ability(ability) {}
  void execute(Game &game)
  {
  }
};

#endif // USEABILITY_H