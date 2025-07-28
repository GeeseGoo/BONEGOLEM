#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "game.h"
#include "view/view.h"
#include <memory>

class Controller {
  std::unique_ptr<Game> game;
  View* view;
  
  public:
    bool testing = false;
    void play(std::istream& in);
    void init(std::istream&in, std::string deck1, std::string deck2, bool isTesting);
    Controller(View* view);
};


#endif // CONTROLLER_H