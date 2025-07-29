#ifndef FIRE_ELEMENTAL_H
#define FIRE_ELEMENTAL_H
#include "../minions/minion.h"
#include "../triggers/triggerlib.h"
#include "../abilities/otherminionbuff.h"
#include "../lib.h"

class FireElemental : public Minion {
public:
  FireElemental(Player &player) : Minion("Fire Elemental", 2,
                                     std::make_unique<MinionEntersTrigger>(std::make_unique<OtherMinionBuff>(0, -1), this, &player),
                                     2, 2, 1, player) {};
  std::string description() override { return "Whenever an opponent's minion enters play, deal 1 damage to it."; }
};

#endif // FIRE_ELEMENTAL_H
