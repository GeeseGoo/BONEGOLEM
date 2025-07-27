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
  public:
    Minion(std::string name, int atk, int def, int actions);
    Minion(std::string name, std::unique_ptr<Trigger> trigger, int atk, int def, int actions);
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
};


#endif // MINION_H