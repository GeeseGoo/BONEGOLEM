#ifndef TRIGGER_H
#define TRIGGER_H

#include "../abilities/ability.h"
#include "../lib.h"
#include "../card.h"
class Action;
class EndTurn;
class StartTurn;
class MinionMoves;
class UseCard;
class Trigger {
  protected:
    std::unique_ptr<Ability> ability;
    Card* card;
  public:
    Trigger(std::unique_ptr<Ability>&& ability, Card* card): ability(std::move(ability)), card(card) {};
    virtual void beTriggered(Action* action, Game& game) {};
    virtual void beTriggered(EndTurn* action, Game& game) {};
    virtual void beTriggered(StartTurn* action, Game& game) {};
    // virtual void beTriggered(MinionMoves* action) {};
    // virtual void beTriggered(UseCard* action) {};
};


#endif // TRIGGER_H