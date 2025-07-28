#include "player.h"
#include "board.h"

using namespace std;
Player::Player(const string& name, const vector<string>& cardNames): name(name), deck(cardNames){
  hand.setPlayer(this);
}

bool Player::isHandFull() {
  return hand.isHandFull();
}

void Player::draw() {
    auto card = deck.draw();
    std::cout << name << " draws "<< card<<" from their deck" << std::endl;
    hand.add(card);
    }


void Player::shuffle() {
        std::cout << "Shuffling " << name << "'s Deck" << std::endl;
      deck.shuffle();
}

Board& Player::getBoard() {
  return board;
}

