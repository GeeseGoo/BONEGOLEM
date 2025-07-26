#include "player.h"

using namespace std;
Player::Player(const string& name, const vector<string>& cardNames): name(name), deck(cardNames){
}

bool Player::isHandFull() {
  return hand.isHandFull();
}

void Player::draw() {
    auto card = deck.draw();
    std::cout << name << " draws "<< card<<" from their deck" << std::endl;
    hand.add(card);
    }

void Player::takeDamage(int dmg) {
  hp -= dmg;
  if (hp <= 0) {
    cout << name << " ded";
  }
}