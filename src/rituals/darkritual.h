#ifndef DARKRITUAL_H
#define DARKRITUAL_H

#include "ritual.h"
#include "../triggers/startturntrigger.h"
#include "../abilities/playerstatbuff.h"

class DarkRitual: public Ritual {

  public:
    DarkRitual(int playerNum): Ritual("Dark Ritual", 0,
      std::make_unique<StartTurnTrigger>(std::make_unique<PlayerStatBuff>(0, 1), this, playerNum), 
      playerNum, 5, 1
    ) {};
    std::string description() override {return "At the start of your turn, gain 1 magic.";}
};


#endif // DARKRITUAL_H