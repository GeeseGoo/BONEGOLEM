#ifndef PLAYER_H
#define PLAYER_H

class Card;
class Action;
class Player {
  int hp;

  public:
    void addToDeck(Card* card);
    void shuffle();
    void action(Action*);

};

#endif // PLAYER_H