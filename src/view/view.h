#ifndef VIEW_H
#define VIEW_H

#include "../game.h"
#include <iostream>
using namespace std;

class View {
  protected:
    Game* game;
  public:
    void assignGame(Game* g){game = g;}
    virtual void displayMinion(int index) = 0;
    virtual void displayHand() = 0;
    virtual void displayBoard() = 0;    
};


#endif // VIEW_H