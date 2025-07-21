#ifndef DECK_H
#define DECK_H
#include <vector>
#include <string>
class Card;
class Deck {
  std::vector<Card*> cards;

  public:
    void shuffle();
    void add(Card*);
    Card* pop(int);
    void loadDeck(std::vector<std::string> cardNames);
};
#endif