#ifndef STANDSTILL_H
#define STANDSTILL_H

#include "ritual.h"
#include "../triggers/minionenterstrigger.h"
#include "../abilities/destroy.h"

class Standstill : public Ritual
{

public:
  Standstill(int playerNum) : Ritual("StandStill", 3,
                                     std::make_unique<MinionEntersTrigger>(std::make_unique<Destroy>(), this),
                                     playerNum, 4, 2) {};
  std::string description() override { return "Whenever a minion enters play, destroy it"; }
};

#endif // STANDSTILL_H