#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "game.h"
#include <memory>

class Controller {
  std::unique_ptr<Game> game;
  public:
    bool testing = false;
    void play(std::istream& in);
    void init(std::istream&in, std::string deck1, std::string deck2, bool isTesting);
    Controller();
};


#endif // CONTROLLER_H