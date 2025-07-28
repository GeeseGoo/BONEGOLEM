#ifndef DARKRITUAL_H
#define DARKRITUAL_H

#include "ritual.h"
#include "../triggers/startturntrigger.h"
#include "../abilities/playerstatbuff.h"

class DarkRitual: public Ritual {
  public:
    DarkRitual(Player& player): Ritual("Dark Ritual",
      std::make_unique<StartTurnTrigger>(std::make_unique<PlayerStatBuff>(0, 1), this), 
      player

    ) {};


};


#endif // DARKRITUAL_H