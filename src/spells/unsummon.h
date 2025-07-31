#ifndef UNSUMMON_H
#define UNSUMMON_H

#include "spell.h"
#include "../game.h"
#include "../abilities/movetohand.h"
using namespace std;

class Unsummon : public Spell
{
  vector<unique_ptr<Ability>> getAbilities(Game &game, Player &player, int onto) override
  {
    vector<unique_ptr<Ability>> abilities;
    abilities.push_back(make_unique<MoveToHand>());
    return abilities;
  }

public:
  Unsummon(int playerNum) : Spell("Unsummon", 1, playerNum) {};

  std::string description() override { return "Return target minion to its owner's hand"; };
};

#endif // UNSUMMON_H