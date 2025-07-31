#ifndef MASTETRSUMMONER
#define MASTETRSUMMONER
#include "../minions/minion.h"
#include "../triggers/triggerlib.h"
#include "../abilities/summonminion.h"
#include "../lib.h"

class MasterSummoner : public Minion
{
public:
  MasterSummoner(int playerNum) : Minion("Master Summoner", 3,
                                     std::make_unique<AbilityTrigger>(std::make_unique<SummonMinion>("Air Elemental", 3), this),
                                     2, 3, 1, playerNum, 2) {};
  std::string description() override { return "Summon a 1/1 air elemental."; }
};

#endif // MASTETRSUMMONER
