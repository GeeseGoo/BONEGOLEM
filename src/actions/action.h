#ifndef ACTION_H
#define ACTION_H

class Game;
class Trigger;
class Board;

class Action{
    virtual void execute(Game& game) = 0;
  public:
    // most of the time we want to do what the action is before we trigger any effects
    // but sometimes this will change...
    virtual void act(Game& game);
    virtual void checkTrigger(Trigger* trig, Board &board, Game &game) = 0;
};


#endif // ACTION_H