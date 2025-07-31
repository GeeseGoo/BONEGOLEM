#ifndef RECHARGE_H
#define RECHARGE_H

#include "spell.h"
#include "../game.h"
#include "../abilities/ritualbuff.h"

class Recharge: public Spell {
    vector<unique_ptr<Ability>> getAbilities(Game& game, Player& player, int onto){
      vector<unique_ptr<Ability>> abilities;
      // std::cout << "onto is " << onto;
      abilities.push_back(std::make_unique<RitualBuff>(player.getNum(), 3));
      return abilities;
    } 
  public:
    Recharge(int playerNum): Spell("Recharge", 1, playerNum){};
    std::string description() override {return "Your ritual gains 3 charges.";}
};

#endif // RECHARGE_H