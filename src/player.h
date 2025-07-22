#ifndef PLAYER_H
#define PLAYER_H

#include <string>
class Card;
class Action;
class Player {
  int hp;
  std::string name;

  public:
    Player(std::string name);
    void addToDeck(Card* card);
    void shuffle();
    void action(Action*);

};

#endif // PLAYER_H