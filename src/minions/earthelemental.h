#include "../minions/minion.h"
#ifndef EarthELemental_H
#define EarthELemental_H

class EarthElemental: public Minion {
  
  public:
    EarthElemental(Player& player): Minion("Earth Elemental", 1, 1, 1, player) {};
};

#endif // EarthELemental_H
