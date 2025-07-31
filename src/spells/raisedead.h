#ifndef RAISEDEAD_H
#define RAISEDEAD_H

#include "spell.h"
#include "../game.h"
#include "../abilities/movefromgraveyard.h"
using namespace std;

class RaiseDead : public Spell
{
  vector<unique_ptr<Ability>> getAbilities(Game &game, Player &player, int onto) override
  {
    vector<unique_ptr<Ability>> abilities;
    abilities.push_back(make_unique<MoveFromGraveyard>(1));
    return abilities;
  }

public:
  RaiseDead(int playerNum) : Spell("Raise Dead", 1, playerNum) {};

  std::string description() override { return "Resurrect the top minion in your graveyard and set its defence to 1"; };
};

#endif // RAISEDEAD_H