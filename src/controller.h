#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "game.h"

class Controller {
  Game game;
  public:
    void play(std::istream& in, bool initPlayers);
    Controller();
};


#endif // CONTROLLER_H