#ifndef ENCHANTMENT_H
#define ENCHANTMENT_H

#include "../lib.h"
#include "../minions/minion.h"

class Board;

// This base class makes an enchantment that does nothing
// override this to add functionality as desired
class Enchantment : public Minion
{
protected:
  std::unique_ptr<Minion> next;

public:
  Enchantment(std::string name, int cost, int playerNum);
  virtual ~Enchantment() = 0;
  // should be able to do everything by overriding only the following 6 functions
  virtual std::string enchantmentTopLeft();
  virtual std::string enchantmentBottomLeft();
  virtual std::string enchantmentBottomRight();
  virtual std::string enchantmentDescription();
  virtual std::string enchantmentName();
  virtual bool deltaActions(int m);
  virtual void setActions(int a);
  virtual Trigger* getTrigger() override;


  int enchantmentCost();
  virtual void onEquip();
  virtual void onRemove();
  int getActions() const override;
  int getAbilityCost() const override;

  Minion *getNext();
  void play(Game &game, Player &player, EnterPlay *action) override;
  bool isEnchantment() override;
  Minion *extractNext() override;
  Minion *getBase() { return next.get(); };

  void takeDamage(int dmg) override;
  int getAtk() const override;
  int getDef() const override;
  void setAtk(int val) override;
  void setDef(int val) override;

  std::string getTopLeft() override;
  std::string getBottomLeft() override;
  std::string getBottomRight() override;
  std::string description() override;
  std::string getName() override;
  int getCost() override;
  std::string getType() override;
  
};

#endif // ENCHANTMENT_H