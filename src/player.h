#ifndef PLAYER_H
#define PLAYER_H

#include "deck.h"
#include "hand.h"
#include "board.h"
#include "graveyard.h"
#include "lib.h"

class Card;
class Action;
class Player
{
  int num;
  int hp = 20;
  int magic = 3;
  std::string name;
  Deck deck;
  std::unique_ptr<Hand> hand;
  Board board;
  Graveyard graveyard;

public:
  Player(const int num, const std::string &name, const std::vector<std::string> &cardNames);
  Player &operator=(const Player &other) = delete;
  Player(const Player &other) = delete;
  Player(Player &&other) = default;
  Player &operator=(Player &&other) = default;

  std::string getName()
  {
    return name;
  };

  int getNum()
  {
    return num;
  }

  void takeDamage(int dmg)
  {
    setHp(hp - dmg);
  };

  int getHp() const
  {
    return hp;
  }

  void setHp(int newHp)
  {
    hp = newHp;
    if (hp <= 0)
    {
      std::cout << name << " is ded" << std::endl;
    }
  };

  int getMagic()
  {
    return magic;
  };

  void setMagic(int m)
  {
    magic = m;
    if (magic <= 0)
    {
      std::cout << name << " out of magic" << std::endl;
    }
  };

  bool deltaMagic(int m)
  {
    m *= -1;
    if (magic + m < 0)
    {
      std::cout << "Out of magic; action aborted" << std::endl;
      return false;
    }
    magic += m;
    return true;
  }

  Hand &getHand()
  {
    return *hand.get();
  }

  Board &getBoard();

  Graveyard &getGraveyard()
  {
    return graveyard;
  }

  void addToDeck(std::string card);
  void action(Action *);
  bool isHandFull();
  void draw();
  void shuffle();
};

#endif // PLAYER_H