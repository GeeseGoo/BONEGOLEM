#ifndef DISENCHANT_H
#define DISENCHANT_H

#include "spell.h"
#include "../game.h"
#include "../abilities/removeenchantment.h"
using namespace std;

class Disenchant : public Spell
{
  vector<unique_ptr<Ability>> getAbilities(Game &game, Player &player, int onto) override
  {
    vector<unique_ptr<Ability>> abilities;
    abilities.push_back(make_unique<RemoveEnchantment>());
    return abilities;
  }

public:
  Disenchant(int playerNum) : Spell("Disenchant", 1, playerNum) {};

  std::string description() override { return "Destroy the top enchantment of target minion"; };
};

#endif // DISENCHANT_H