#ifndef BLIZZARD_H
#define BLIZZARD_H

#include "spell.h"
#include "../game.h"

class Minion;
class Blizzard: public Spell {
  Ability* getAbility() override {
    return nullptr; // THIS IS TEMPORARY, WILL NEED TO CHANGE THIS TO TAKEDAMAGE INSTEAD
  }
  public:
  Blizzard(Player& player): Spell("Blizzard", 3, player){};

  std::string description() override {return "Deal 2 damage to all minions.";}
};



#endif // BLIZZARD_H