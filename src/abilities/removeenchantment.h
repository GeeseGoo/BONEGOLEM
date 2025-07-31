#ifndef REMOVE_ENCHANTMENT_H
#define REMOVE_ENCHANTMENT_H

#include "ability.h"
#include "../game.h"
#include "../player.h"
#include "../card.h"
#include "../actions/action.h"
#include "../lib.h"

class RemoveEnchantment : public Ability
{

  void execute(Game &game, Card *card, Action *action, int player, int onto) override
  {
    game.getPlayers().at(player).getBoard().detach(onto);
  }

public:
};

#endif // REMOVE_ENCHANTMENT_H