#ifndef BLIZZARD_H
#define BLIZZARD_H

#include "spell.h"
#include "../game.h"

class Blizzard: public Spell {
    vector<unique_ptr<Ability>> getAbilities(Game& game, Player& player, int onto){
      vector<unique_ptr<Ability>> abilityList = {};
      for(unsigned int i = 0; i < game.getPlayers().size(); i++){
        int index = (game.getPlayerIdx()+i) % game.getPlayers().size();
        abilityList.push_back(std::make_unique<AllMinionBuff>(0, -2, &game.getPlayers().at(index)));
      }
      return abilityList;
    } 
  public:
    Blizzard(int playerNum): Spell("Blizzard", 3, playerNum){};
    std::string description() override {return "Deal 2 damage to all minions.";}
};

#endif // BLIZZARD_H