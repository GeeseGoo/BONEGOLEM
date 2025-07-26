#include "deck.h"
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include "lib.h"
using namespace std;

Deck::Deck(const vector<string>& cardNames): cardNames(cardNames) {

}

void Deck::shuffle() {
  random_device rd;
  mt19937 gen(rd());
  std::shuffle(cardNames.begin(), cardNames.end(), gen);
}

string Deck::draw() {
  if (cardNames.empty()) throw std::runtime_error("Deck is empty");
  string card = cardNames.back();
  cardNames.pop_back();
  return card;
}