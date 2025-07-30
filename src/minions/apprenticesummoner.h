#ifndef APPRENTICESUMMONER_H
#define APPRENTICESUMMONER_H
#include "../minions/minion.h"
#include "../triggers/triggerlib.h"
#include "../abilities/summonminion.h"
#include "../lib.h"

class ApprenticeSummoner : public Minion
{
public:
  ApprenticeSummoner(int playerNum) : Minion("Apprentice Summoner", 2,
                                     std::make_unique<AbilityTrigger>(std::make_unique<SummonMinion>("Air Elemental", 1), this),
                                     1, 1, 1, playerNum, 1) {};
  std::string description() override { return "Summon a 1/1 air elemental."; }
};

#endif // APPRENTICESUMMONER_H
