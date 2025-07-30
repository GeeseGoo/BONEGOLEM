#ifndef ACTION_H
#define ACTION_H

class Game;
class Trigger;
class Board;

class Action{
    virtual void execute(Game& game) = 0;
  public:
    virtual ~Action() = default;  
    void act(Game& game);
    virtual bool checkTrigger(Trigger* trig, Board &board, Game &game) = 0;
};


#endif // ACTION_H