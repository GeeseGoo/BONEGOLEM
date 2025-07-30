#ifndef MINION_H
#define MINION_H

#include "../lib.h"
#include "../card.h"
#include "../triggers/trigger.h"
#include "../actions/killminion.h"

class Board;
class Player;
class Game;
class Minion: public Card {
  protected:
    int atk;
    int def;
    int actions;
    int abilityCost = -1; // -1 means minion does not have an activated ability
    bool isDead = true;
    Game* game = nullptr;
    Minion* base = this;
  public:
    Minion(std::string name, int cost, int atk, int def, int actions, int playerNum);
    Minion(std::string name, int cost, std::unique_ptr<Trigger> trigger, int atk, int def, int actions, int playerNum, int abilityCost = -1);
    virtual void play(Game &game, Player &player, EnterPlay* action) override;
    void attack(Player& other);
    virtual void takeDamage(int dmg);
    virtual int getAtk() const {return atk;}
    virtual int getDef() const {return def;}
    virtual void setAtk(int val) {atk = val;}
    virtual void setDef(int val) {def = val;}
    virtual int getActions() const {return actions;}
    virtual int getAbilityCost() const {return abilityCost;}
    std::string getBottomLeft() override;
    std::string getBottomRight() override;
    std::string getTopLeft() override;
    std::string getType() override {return "Minion";}
    virtual bool isEnchantment() {return false;}
};


#endif // MINION_H