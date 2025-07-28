#ifndef POTIONSELLER_H
#define POTIONSELLER_H
#include "../minions/minion.h"
#include "../triggers/endturn.h"
#include "../abilities/allminionbuff.h"
#include "../lib.h"

class PotionSeller : public Minion
{

public:
  PotionSeller(Player &player) : Minion("Potion Seller", 2,
                                        std::make_unique<EndTurnTrigger>(std::make_unique<AllMinionBuff>(0, 1), this),
                                        1, 1, 1, player) {};
  std::string description() override { return "At the end of your turn, all your minions get +0/+1."; }
};

#endif // POTIONSELLER_H
