#ifndef STARTTURN_h
#define STARTTURN_h

#include "../actions/startTurn.h"
#include "trigger.h"

class StartTurnTrigger: public Trigger {

  public:
    void beTriggered(StartTurn* start, Game& game) override {
      ability->activate(game);
    };
};


#endif // STARTTURN