#ifndef NOVICE_PYROMANCER_H
#define NOVICE_PYROMANCER_H
#include "../minions/minion.h"
#include "../triggers/triggerlib.h"
#include "../abilities/otherminionbuff.h"
#include "../lib.h"

class NovicePyromancer : public Minion {
public:
  NovicePyromancer(int playerNum) : Minion("Novice Pyromancer", 1,
                                     std::make_unique<AbilityTrigger>(std::make_unique<OtherMinionBuff>(0, -1), this),
                                     0, 1, 1, playerNum, 1) {};
  std::string description() override { return "Deal 1 damage to target minion."; }
};

#endif // NOVICE_PYROMANCER_H
