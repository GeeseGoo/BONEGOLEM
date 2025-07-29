#include "card.h"
#include "triggers/trigger.h"
#include "player.h"
Card::Card(std::string name, int cost, Player& player): player(player), name(name), cost{cost} {};
Card::Card(std::string name, int cost, std::unique_ptr<Trigger> trigger, Player& player): trigger(std::move(trigger)),player(player), name(name), cost{cost} {};
Trigger* Card::getTrigger() {
  if(trigger) return trigger.get();
  else return nullptr;
}