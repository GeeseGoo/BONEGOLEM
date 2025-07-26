#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "deck.h"
#include "hand.h"
#include "board.h"
#include <iostream>
class Card;
class Action;
class Player {
  int hp;
  std::string name;
  Deck deck;
  Hand hand;
  Board board;

  public:
    Player(const std::string& name, const std::vector<std::string>& cardNames);
    Player& operator=(const Player& other) = delete;
    Player(const Player& other) = delete;
    Player(Player&& other) = default;
    Player& operator=(Player&& other) = default;

    std::string getName() {
      return name;
    };

    void takeDamage(int dmg) {
        hp -= dmg;
        if (hp<= 0) {
          std::cout << name << " is ded"<< std::endl;
        }
    }

    Hand& getHand() {
      return hand;
    }

    Board& getBoard();

    void dealDamage(int dmg);
    
    void addToDeck(std::string card);
    void action(Action*);
    bool isHandFull();
    void draw();
    void shuffle();
};

#endif // PLAYER_H