#include "../minions/minion.h"
#ifndef AIRELEMENTAL_H
#define AIRELEMENTAL_H

class AirElemental : public Minion
{

public:
  AirElemental(Player &player) : Minion("Air Elemental", 0, 1, 1, 1, player) {};
  std::string description() override { return ""; }
};

#endif // AIRELEMENTAL_H
