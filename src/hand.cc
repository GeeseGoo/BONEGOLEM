#include "hand.h"
#include "lib.h"
#include "createCard.h"
using namespace std;

bool Hand::isHandFull() const {
  if (cards.size() >= 5) return true;
  return false;
}

Hand::Hand(Player* p): playerNum{p->getNum()} {
  cout << this << " Created hand for player " << p->getNum() << endl;
};

void Hand::add(string cardName) {
  std::cout << this << " adding card to player " << playerNum << std::endl;
  cards.emplace_back(createCard(cardName, playerNum));
}

std::size_t Hand::numCards() const {
  return cards.size();
}

void Hand::pop(unsigned int i){
  if (!cards.at(i)) {
    throw std::runtime_error("Card not found: " + std::to_string(i));
  }
  std::vector<std::unique_ptr<Card>> newCards;
  for(unsigned int x = 0; x < cards.size(); x++){
    if(x != i){
      newCards.push_back(std::move(cards.at(x)));
    }
  }
  cards = std::move(newCards);
}
