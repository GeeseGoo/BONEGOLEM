#ifndef POTIONSELLER_H
#define POTIONSELLER_H
#include "../minions/minion.h"
#include "../triggers/endTurn.h"
#include "../abilities/allminionbuff.h"
#include "../lib.h"

class PotionSeller: public Minion {
  
  public:
    PotionSeller(): Minion("Potion Seller", 
      std::make_unique<EndTurnTrigger>(std::make_unique<AllMinionBuff>(0, 1), this),
      1, 1, 1) {};
};

#endif // POTIONSELLER_H
