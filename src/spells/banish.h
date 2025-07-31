#ifndef BANISH_H
#define BANISH_H

#include "spell.h"
#include "../game.h"
#include "../abilities/destroy.h"

class Banish : public Spell
{
  vector<unique_ptr<Ability>> getAbilities(Game &game, Player &player, int onto)
  {
    vector<unique_ptr<Ability>> abilities;
    // std::cout << "onto is " << onto;
    abilities.push_back(std::make_unique<Destroy>());
    return abilities;
  }

public:
  Banish(int playerNum) : Spell("Banish", 2, playerNum) {};
  std::string description() override { return "Destroy target minion or ritual."; }
};

#endif // BANISH_H