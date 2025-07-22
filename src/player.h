#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "deck.h"
class Card;
class Action;
class Player {
  int hp;
  std::string name;
  Deck deck;

  public:
    Player(const std::string& name, const std::vector<std::string>& cardNames);
    void addToDeck(std::string card);
    void shuffle();
    void action(Action*);

};

#endif // PLAYER_H