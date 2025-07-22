#include "game.h"
#include <string>
using namespace std;
Game::Game(std::string name1, std::string name2, std::vector<std::string> deck1, std::vector<std::string> deck2): 
p1(name1, deck1), p2(name2, deck2)  {

}