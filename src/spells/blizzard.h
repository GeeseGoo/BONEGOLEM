#ifndef BLIZZARD_H
#define BLIZZARD_H

#include "spell.h"
#include "../game.h"

class Minion;
class Blizzard: public Spell {
  int dmg = 2;

  public:
  Blizzard(Player& player): Spell("Blizzard", 3, player){};

  void execute(Game& game) override {
    auto &players = game.getPlayers();
    for(auto &player: players) {
      std::vector<Minion*> minions = player.getBoard().getMinions();
      for (auto minion: minions) {
        minion->takeDamage(dmg);
      }
    }
  }
  std::string description() override {return "Deal 2 damage to all minions.";}
};



#endif // BLIZZARD_H