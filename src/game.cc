#include "game.h"
#include "actions/action.h"
#include <iostream>
#include <string>
using namespace std;
Game::Game(std::string name1, std::string name2, std::vector<std::string> deck1, std::vector<std::string> deck2):
activePlayer(1) {
  players.emplace_back(Player(name1, deck1));
  players.emplace_back(Player(name2, deck2));
}

Player& Game::getActivePlayer() {
  return players[activePlayer];
}

void Game::nextPlayer() {
  activePlayer = (activePlayer + 1) % playerCount;
  cout << getActivePlayer().getName() << "'s Turn"<< endl;
}

void Game::action(std::unique_ptr<Action> action){
  action->execute(*this);
  actionHistory.push_back(std::move(action));
}