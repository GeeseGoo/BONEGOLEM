#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "game.h"
#include <memory>

class Controller {
  std::unique_ptr<Game> game;
  public:
    void play(std::istream& in, bool initPlayers);
    Controller();
};


#endif // CONTROLLER_H