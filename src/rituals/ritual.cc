#include "ritual.h"
#include "../card.h"
#include "../triggers/trigger.h"
#include "../game.h"
#include "../board.h"
#include "../lib.h"


void Ritual::play(Game &game, Player &player, EnterPlay* action) {
  game.getActivePlayer().getBoard().addCard(this);
};

Ritual::Ritual(std::string name, int cost, std::unique_ptr<Trigger> trigger, int playerNum, int initialCharges, int ritualCost): Card(name, cost, std::move(trigger), playerNum), charges{initialCharges}, ritualCost{ritualCost} {};

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