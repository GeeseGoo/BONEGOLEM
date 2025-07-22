#ifndef DECK_H
#define DECK_H
#include <vector>
#include <string>
class Card;
class Deck {
  std::vector<std::string> cardNames;

  public:
    void shuffle();
    std::string draw();
    Deck(const std::vector<std::string>& cardNames);
};
#endif