#ifndef TRIGGER_H
#define TRIGGER_H


class Action;
class EndTurn;
class StartTurn;
class MinionMoves;
class UseCard;
class Ability;
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