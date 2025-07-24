#include "player.h"

using namespace std;
Player::Player(const string& name, const vector<string>& cardNames): name(name), deck(cardNames){
}

bool Player::isHandFull() {
  return hand.isHandFull();
}

void Player::draw() {
      std::cout << name << " draws a card from their deck" << std::endl;
      hand.add(deck.draw());
    }