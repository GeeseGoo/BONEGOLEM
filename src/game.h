#ifndef GAME_H
#define GAME_H
#include <string>
#include <vector>
#include "lib.h"
#include "player.h"
#include <map>
#include "actions/action.h"
using namespace std;

class Trigger;
class Game
{
  std::vector<Player> players;
  std::vector<std::unique_ptr<Action>> actionHistory;
  int activePlayer;
  const int playerCount = 2;

public:
  Game(std::string p1, std::string p2, std::vector<std::string> deck1, std::vector<std::string> deck2);
  Player &getActivePlayer();
  int getPlayerNum()
  {
    return activePlayer + 1;
  };
  int getPlayerIdx()
  {
    return activePlayer;
  }
  int getInactivePlayerIdx()
  {
    return (activePlayer + 1) % playerCount;
  }
  Player &getInactivePlayer()
  {
    return players[(activePlayer + 1) % playerCount];
  };
  std::vector<Player> &getPlayers()
  {
    return players;
  };
  void takeDamage(Minion &minion, Board &board, int dmg);
  void nextPlayer();

  void action(std::unique_ptr<Action> action);

  Minion *getCurrentMinion(int index);
  Hand *getCurrentHand();
  vector<Board *> getBoards();
  void trigger(Action* action);
};

#endif // GAME_H