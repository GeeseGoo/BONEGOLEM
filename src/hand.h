#ifndef HAND_H
#define HAND_H

#include <vector>
#include <memory>
#include "card.h"
class Hand {
  std::vector<std::unique_ptr<Card>> cards;
  public:
    void add(std::string card);
    void add(std::unique_ptr<Card> card);
    void pop(int);
    bool isHandFull() const;
};
#endif // HAND_H