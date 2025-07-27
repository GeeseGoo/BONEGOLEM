#ifndef ENDTURN_h
#define ENDTURN_h

#include "../actions/endTurn.h"
#include "trigger.h"
class Game;
class EndTurnTrigger: public Trigger {

  public:
    void beTriggered(EndTurn* action, Game& game) override {
      ability->activate(game);
    };
};


#endif // ENDTURN_h