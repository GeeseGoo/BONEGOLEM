#include "controller.h" 
#include "game.h"
#include <string>
#include <iostream>
using namespace std;

Controller::Controller(): game(game) {}

void Controller::play(istream& in, bool initPlayers) {
  
  string cmd;

  if (initPlayers) {
    string p1, p2;
    cin >> p1 >> p2;

  }

  while (in >> cmd) {
    if(cmd == "help") {
      cout << R"(Commands: help-- Display this message.
 end-- End the current player’s turn.
 quit-- End the game.
 attack minion other-minion-- Orders minion to attack other-minion.
 attack minion-- Orders minion to attack the opponent.
 play card [target-player target-card]-- Play card, optionally targeting target-card owned by target-player.
 use minion [target-player target-card]-- Use minion’s special ability, optionally targeting target-card owned by target-player.
 inspect minion-- View a minion’s card and all enchantments on that minion.
 hand-- Describe all cards in your hand.
 board-- Describe all cards on the board.)" << endl;
    }

    if (cmd == "end") {
      cout << "end";
    }

    if (cmd == "quit") {
      cout << "quit"<< endl;
    }
    if (cmd == "draw") {
      cout << "draw"<< endl;
    }
if (cmd == "discard") {
  cout << "discard"<< endl;
}
if (cmd == "attack") {
  cout << "attack"<< endl;
}
if (cmd == "play") {
  cout << "play"<< endl;
}
if (cmd == "use") {
  cout << "use"<< endl;
}
if (cmd == "inspect") {
  cout << "inspect"<< endl;
}
if (cmd == "hand") {
  cout << "hand"<< endl;
}
if (cmd == "board") {
  cout << "board"<< endl;
}
  }
}