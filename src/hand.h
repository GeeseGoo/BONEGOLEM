#ifndef HAND_H
#define HAND_H

#include <vector>
#include <memory>
#include "card.h"
#include <stdexcept>

class Player;
class Hand {
  std::vector<std::unique_ptr<Card>> cards;
  int playerNum;
  public:
    Hand(Player* p);
    void add(std::string cardName);
    void add(std::unique_ptr<Card> card);
    Card& getCard(int i) {
      if (!cards[i]) {
        throw std::runtime_error("Card not found: " + std::to_string(i));
      }

      return *(cards[i]);
    };


    std::unique_ptr<Card> extractCard(int i) {
      if (!cards[i]) {
        throw std::runtime_error("Card not found: " + std::to_string(i));
      }

      auto card = std::move(cards[i]);
      cards.erase(cards.begin() + i);
      return card;
    }

    void pop(int);
    bool isHandFull() const;
    std::size_t numCards() const;
};
#endif // HAND_H