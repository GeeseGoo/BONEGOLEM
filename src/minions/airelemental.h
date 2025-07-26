#include "../minions/minion.h"
#ifndef AIRELEMENTAL_H
#define AIRELEMENTAL_H

class AirElemental: public Minion {
  
  public:
    AirElemental(): Minion("Air Elemental", 1, 1, 1) {};
};

#endif // AIRELEMENTAL_H
