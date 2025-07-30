#include "controller.h"
#include "game.h"
#include "view/view.h"
#include <string>
#include <iostream>
#include <fstream>
#include <memory>
#include "actions/actionLib.h"
#include <sstream>
#include <algorithm>
#include <cctype>
using namespace std;

// wtf does this do
void trim(std::string &s)
{
  s.erase(s.begin(), std::find_if(s.begin(), s.end(),
                                  [](unsigned char c)
                                  { return !std::isspace(c); }));
  s.erase(std::find_if(s.rbegin(), s.rend(),
                       [](unsigned char c)
                       { return !std::isspace(c); })
              .base(),
          s.end());
}

Controller::Controller(View *view) : view{view} {}

void Controller::init(istream &in, string deck1Name, string deck2Name, bool isTesting)
{
  // Assign testing state
  testing = isTesting;
  // read in player names
  string p1, p2;
  in >> p1 >> p2;

  // read deck files
  vector<string> deck1, deck2;
  ifstream f1(deck1Name);
  ifstream f2(deck2Name);

  if (!f1)
  {
    std::cerr << "error with deck1";
  }
  if (!f2)
  {
    std::cerr << "error with deck2";
  }

  string line;
  while (getline(f1, line))
  {
    if (!line.empty())
    {
      trim(line);
      deck1.push_back(line);
    }
  }
  while (getline(f2, line))
  {
    if (!line.empty())
    {
      trim(line);
      deck2.push_back(line);
    }
  }

  game = make_unique<Game>(p1, p2, deck1, deck2);
  // give view access to the game
  view->assignGame(game.get());
  // shuffle decks
  if(!testing){
    for (Player &player : game->getPlayers()){
      player.shuffle();
    }
  }
  game->action(make_unique<StartTurn>());
}

// start the main game loop
void Controller::play(istream &in)
{

  string line;
  // input management
  while (getline(in, line))
  {
    istringstream iss(line);
    vector<string> tokens;
    string token;
    while (iss >> token)
    {
      tokens.push_back(token);
    }
    if (tokens.empty())
      continue;

    if (tokens[0] == "help")
    {
      cout << R"(Commands: help-- Display this message.
 end-- End the current player’s turn.
 quit-- End the game.
 attack minion other-minion-- Orders minion to attack other-minion.
 attack minion-- Orders minion to attack the opponent.
 play card [target-player target-card]-- Play card, optionally targeting target-card owned by target-player.
 use minion [target-player target-card]-- Use minion’s special ability, optionally targeting target-card owned by target-player.
 inspect minion-- View a minion’s card and all enchantments on that minion.
 hand-- Describe all cards in your hand.
 board-- Describe all cards on the board.)"
           << endl;
    }

    if (tokens[0] == "end")
    {
      game->action(make_unique<EndTurn>());
      game->action(make_unique<StartTurn>());
    }

    if (tokens[0] == "quit")
    {
      cout << "quit" << endl;
      break;
    }
    if (tokens[0] == "draw" && testing)
    {
      game->getActivePlayer().draw();
      cout << "draw" << endl;
    }
    if (tokens[0] == "discard")
    {
      int index = std::stoi(tokens[1]);
      game->getActivePlayer().getHand().pop(index);
      cout << "discard" << endl;
    }
    if (tokens[0] == "attack")
    {
      if (tokens.size() == 2)
      {
        game->action(make_unique<AttackPlayer>(std::stoi(tokens[1])));
      }
      if (tokens.size() == 3)
      {
        game->action(make_unique<AttackMinion>(std::stoi(tokens[1]), std::stoi(tokens[2])));
      }
    }
    if (tokens[0] == "play")
    {
      if (tokens.size() == 2)
      {
        std::cout << game->getPlayerIdx() << " is player";
        game->action(make_unique<EnterPlay>(std::stoi(tokens[1]) - 1, game->getPlayerIdx(), -1));
      }
      if (tokens.size() == 4)
      {
        if(tokens[3] == "r"){
          game->action(make_unique<EnterPlay>(std::stoi(tokens[1]) - 1, std::stoi(tokens[2]) - 1, -1));
        }else{
          game->action(make_unique<EnterPlay>(std::stoi(tokens[1]) - 1, std::stoi(tokens[2]) - 1, std::stoi(tokens[3]) - 1));
        }
      }
    }
    if (tokens[0] == "use")
    {
      if (tokens.size() == 2)
      {
        game->action(make_unique<UseAbility>(std::stoi(tokens[1]) - 1, game->getPlayerIdx(), -1));
      }
      if (tokens.size() == 4){
        if(tokens[3] == "r"){
          game->action(make_unique<UseAbility>(std::stoi(tokens[1]) - 1, std::stoi(tokens[2]) - 1, -1));
        }else{
          game->action(make_unique<UseAbility>(std::stoi(tokens[1]) - 1, std::stoi(tokens[2]) - 1, std::stoi(tokens[3]) - 1));
        }
        cout << "use" << endl;
      }
    }
    if (tokens[0] == "inspect")
    {
      view->displayMinion(std::stoi(tokens[1]));
    }
    if (tokens[0] == "hand")
    {
      view->displayHand();
    }
    if (tokens[0] == "board")
    {
      view->displayBoard();
    }
  }
}
