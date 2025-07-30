#include "../minions/minion.h"
#ifndef AIRELEMENTAL_H
#define AIRELEMENTAL_H

class AirElemental : public Minion
{

public:
  AirElemental(int playerNum) : Minion("Air Elemental", 0, 1, 1, 1, playerNum) {};
  std::string description() override { return ""; }
};

#endif // AIRELEMENTAL_H
