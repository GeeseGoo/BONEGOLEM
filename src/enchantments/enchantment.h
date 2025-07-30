#ifndef ENCHANTMENT_H
#define ENCHANTMENT_H

#include "../lib.h"
#include "../minions/minion.h"

class Enchantment : public Minion
{
protected:
  std::unique_ptr<Minion> next;

  public:
    Enchantment(std::string name, int cost, std::unique_ptr<Minion>&& minion, int playerNum): Minion(name, cost, 0, 0, 0, playerNum), next(std::move(minion)) {};
    virtual Minion* getNext() = 0;
    std::string getTopLeft() override {return "";}
    std::string getType() override {return "Enchantment";}
    virtual Minion *getNext() = 0;
    void setNext(std::unique_ptr<Minion> &&minion)
    {
      next = std::move(minion);
    };
    void play(Game& game, Player& player, int onto) override;
    std::string getTopLeft() override { return ""; };
};

#endif // ENCHANTMENT_H