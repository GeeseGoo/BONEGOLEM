#ifndef ACTION_H
#define ACTION_H

class Game;
class Action{

  public:
    virtual void execute(Game& game) = 0;
};


#endif // ACTION_H