#include "card.h"
#include "triggers/trigger.h"
#include "player.h"
Card::Card(std::string name, int cost, int playerNum): playerNum(playerNum), name(name), cost{cost} {};
Card::Card(std::string name, int cost, std::unique_ptr<Trigger> trigger, int playerNum): trigger(std::move(trigger)),playerNum(playerNum), name(name), cost{cost} {};
Trigger* Card::getTrigger() {
  if(trigger) return trigger.get();
  else return nullptr;
}