#ifndef AURAOFPOWER_H
#define AURAOFPOWER_H

#include "ritual.h"
#include "../triggers/minionenterstrigger.h"
#include "../abilities/otherminionbuff.h"

class AuraOfPower: public Ritual {

  public:
    AuraOfPower(int playerNum): Ritual("Aura of Power", 1,
      std::make_unique<MinionEntersTrigger>(std::make_unique<OtherMinionBuff>(1, 1), this, playerNum + 1), 
      playerNum, 4, 1
    ) {};
    std::string description() override {return "Whenever a minion enters play under your control, it gains +1/+1.";}
};


#endif // AURAOFPOWER_H