#include "../minions/minion.h"
#ifndef AIRELEMENTAL_H
#define AIRELEMENTAL_H

class AirElemental: public Minion {
  
  public:
    AirElemental(Player& player): Minion("Air Elemental", 1, 1, 1, player) {};
};

#endif // AIRELEMENTAL_H
