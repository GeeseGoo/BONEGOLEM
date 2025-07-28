#ifndef GAME_H
#define GAME_H
#include <string>
#include <vector>
#include "lib.h"
#include "player.h"
#include <map>

#include "actions/action.h"
class Trigger;
class Game {
  std::vector<Player> players;
  std::vector<std::unique_ptr<Action>> actionHistory;
  std::map<int, std::vector<Trigger*>> triggers = {{0, {}}, {1, {}}};
  int activePlayer;
  const int playerCount = 2;
  public:
    Game(std::string p1, std::string p2, std::vector<std::string> deck1, std::vector<std::string> deck2);
    Player& getActivePlayer();
    int getPlayerNum() {
      return activePlayer + 1;
    };
    int getPlayerIdx() {
      return activePlayer;
    }
    int getInactivePlayerIdx() {
      return (activePlayer + 1) % playerCount;
    }
    Player& getInactivePlayer() {
      return players[(activePlayer + 1) % playerCount];
    };
    std::vector<Player>& getPlayers() {
      return players;
    };
    void nextPlayer();

    void notifyEndTurnTriggers(EndTurn* action) {
      for (auto trigger: getTriggers()) {
        trigger->beTriggered(action, *this); 
        }
    };

    void notifyStartTurnTriggers(StartTurn* action) {
      for (auto trigger: getTriggers()) {
        trigger->beTriggered(action, *this); 
        } 
      };

    void addTrigger(Trigger* trigger);

    const std::vector<Trigger*> getTriggers() {
      std::vector<Trigger*> allTriggers;
      for(auto t: triggers[getPlayerIdx()]) {
        allTriggers.emplace_back(t);
      }
      for(auto t: triggers[getInactivePlayerIdx()]) {
        allTriggers.emplace_back(t);
      }
      return allTriggers;
    };

    void action(std::unique_ptr<Action> action);
};

#endif // GAME_H