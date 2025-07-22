#ifndef GAME_H
#define GAME_H
#include <string>
#include <vector>
#include "player.h"
class Game {
  Player p1, p2;
  public:
    Game(std::string p1, std::string p2, std::vector<std::string> deck1, std::vector<std::string> deck2);
};

#endif // GAME_H