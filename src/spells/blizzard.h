#ifndef BLIZZARD_H
#define BLIZZARD_H

#include "spell.h"
#include "../game.h"

class Minion;
class Blizzard: public Spell {
  int dmg = 2;

  public:
  Blizzard(Player& player): Spell(3, "Blizzard", player){};

  void execute(Game& game) override {
    auto &players = game.getPlayers();
    for(auto &player: players) {
      std::vector<Minion*> minions = player.getBoard().getMinions();
      for (auto minion: minions) {
        minion->takeDamage(dmg);
      }
    }
  }
};



#endif // BLIZZARD_H