#ifndef TRIGGER_H
#define TRIGGER_H

#include "triggerlib.h"
#include "../actions/actionLib.h"
#include "../abilities/ability.h"

class Action;
class Trigger {
  protected:
    Ability* ability;
  public:
    virtual void beTriggered(Action* action, Game& game) {};
    virtual void beTriggered(EndTurn* action, Game& game) {};
    virtual void beTriggered(StartTurn* action, Game& game) {};
    // virtual void beTriggered(MinionMoves* action) {};
    // virtual void beTriggered(UseCard* action) {};
};


#endif // TRIGGER_H