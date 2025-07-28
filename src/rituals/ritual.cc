#include "ritual.h"
#include "../card.h"
#include "../triggers/trigger.h"
#include "../game.h"
#include "../board.h"
#include "../lib.h"


void Ritual::play(Game& game, std::unique_ptr<Card>&& self, Player& player) {
      // add trigger to game
      std::cout << " adding ritual trigger" << std::endl;
      player.getBoard().addTrigger(this->getTrigger());
      
      Card* rawCard = self.release();
      rawCard->addToBoard(game.getActivePlayer().getBoard());
    };

    void Ritual::addToBoard(Board& board) {
      board.addCard(this);
    }

Ritual::Ritual(std::string name, int cost, std::unique_ptr<Trigger> trigger, Player& player, int initialCharges, int ritualCost): Card(name, cost, std::move(trigger), player), charges{initialCharges}, ritualCost{ritualCost} {};

string Ritual::getBottomLeft(){
  return "";
}
string Ritual::getBottomRight(){
  return to_string(charges);
}
string Ritual::getTopLeft(){
  return to_string(ritualCost);
}


// Ritual::~Ritual() {}