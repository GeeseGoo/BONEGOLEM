#ifndef ENCHANTMENT_H
#define ENCHANTMENT_H

#include "../lib.h"
#include "../minions/minion.h"

class Board;

// This class is actually concrete, it makes an enchantment that does nothing
// override this to add functionality as desired
class Enchantment : public Minion {
protected:
  std::unique_ptr<Minion> next;

  public:
    Enchantment(std::string name, int cost, int playerNum);

    // should be able to do everything by overriding only the following 6 functions
    virtual std::string enchantmentTopLeft();
    virtual std::string enchantmentBottomLeft();
    virtual std::string enchantmentBottomRight();
    virtual std::string enchantmentDescription();
    virtual void onEquip();
    int getActions() const;
    int getAbilityCost() const;
    
    Minion *getNext();
    void play(Game &game, Player &player, EnterPlay* action) override;
    bool isEnchantment() override;
    
    void takeDamage(int dmg);
    int getAtk() const;
    int getDef() const;
    void setAtk(int val);
    void setDef(int val);
    
    std::string getTopLeft() override;
    std::string getBottomLeft() override;
    std::string getBottomRight() override;
    std::string description() override;
    std::string getName() override;
    int getCost() override;
    int enchantmentCost();
    std::string getType() override;
};

#endif // ENCHANTMENT_H