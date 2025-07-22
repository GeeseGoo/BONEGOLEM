#ifndef GAME_H
#define GAME_H
#include <string>
#include "player.h"
class Game {
  Player p1, p2;
  public:
    Game(std::string p1, std::string p2);
};

#endif // GAME_H