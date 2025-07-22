#include "deck.h"
#include <vector>
#include <string>
#include <algorithm>
#include <random>
using namespace std;

Deck::Deck(const vector<string>& cardNames): cardNames(cardNames) {

}

void Deck::shuffle() {
  random_device rd;
  mt19937 gen(rd());
  std::shuffle(cardNames.begin(), cardNames.end(), gen);
}

string Deck::draw() {
  string card = cardNames.back();
  cardNames.pop_back();
  return card;
}