#include "game.h"
#include "actions/actionLib.h"
#include "triggers/trigger.h"
#include <iostream>
#include <string>
using namespace std;
Game::Game(std::string name1, std::string name2, std::vector<std::string> deck1, std::vector<std::string> deck2) : activePlayer(1)
{
  players.emplace_back(Player(0, name1, deck1));
  players.emplace_back(Player(1, name2, deck2));
}

Player &Game::getActivePlayer() {
  return players[activePlayer];
}

void Game::nextPlayer() {
  activePlayer = (activePlayer + 1) % playerCount;
  cout << getActivePlayer().getName() << "'s Turn" << endl;
}

void Game::action(std::unique_ptr<Action> action) {
  action->act(*this);
  actionHistory.push_back(std::move(action));
}

void Game::trigger(Action* action){
  for(unsigned int i = 0; i < players.size(); i++){
    players.at((getPlayerIdx()+i)%players.size()).getBoard().trigger(action, *this);
  }
}

Hand *Game::getCurrentHand()
{
  return &getActivePlayer().getHand();
}

vector<Board *> Game::getBoards()
{
  vector<Board *> boards = {};
  for (unsigned int i = 0; i < players.size(); i++)
  {
    boards.push_back(&players[i].getBoard());
  }
  return boards;
}

void Game::takeDamage(Minion &minion, Board &board, int dmg)
{
  minion.takeDamage(dmg);
  if (minion.getDef() <= 0)
  {
    this->action(make_unique<LeavePlay>(minion, board));
  }
}
