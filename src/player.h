#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "deck.h"
#include "hand.h"
#include "board.h"
#include "graveyard.h"
#include <iostream>
class Card;
class Action;
class Player {
    int hp = 20;
    int magic = 0;
    std::string name;
    Deck deck;
    Hand hand;
    Board board;
    Graveyard graveyard;
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
      setHp(hp - dmg);
    };

    int getHp() const {
      return hp;
    }

    void setHp(int newHp) {
      hp = newHp;
      if (hp<= 0) {
      std::cout << name << " is ded"<< std::endl;
      }
    };

    int getMagic() {
      return magic;
    };

    void setMagic( int m) {
      magic = m;
      if (magic <= 0) {
        std::cout << name << " out of magic" << std::endl;
      }
    };

    Hand& getHand() {
      return hand;
    }

    Board& getBoard();

    Graveyard& getGraveyard() {
      return graveyard;
    }

    void dealDamage(int dmg);
    
    void addToDeck(std::string card);
    void action(Action*);
    bool isHandFull();
    void draw();
    void shuffle();
};

#endif // PLAYER_H