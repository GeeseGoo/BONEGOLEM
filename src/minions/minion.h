#ifndef MINION_H
#define MINION_H


#include "../lib.h"
#include "../card.h"
#include "../triggers/trigger.h"

class Board;
class Player;
class Game;
class Minion: public Card {
  int atk;
  int def;
  int actions;
  int abilityCost = -1; // -1 means minion does not have an activated ability
  public:
    Minion(std::string name, int cost, int atk, int def, int actions, Player& player);
    Minion(std::string name, int cost, std::unique_ptr<Trigger> trigger, int atk, int def, int actions, Player& player);
    void play(Game& game, std::unique_ptr<Card>&& self) override;
    void attack(Minion& other);
    void attack(Player& other);
    void takeDamage(int dmg) {
        def -= dmg;
        if (def<= 0) {
          std::cout << name << " is ded"<< std::endl;
        }
    };

    void addToBoard(Board& board) override;

    virtual int getAtk() const {return atk;};
    virtual int getDef() const {return def;};
     void setAtk(int val) {atk = val;};
     void setDef(int val) {def = val;};
    virtual int getActions() const {return actions;};
    std::string getBottomLeft() override;
    std::string getBottomRight() override;
    std::string getTopLeft() override;
};


#endif // MINION_H