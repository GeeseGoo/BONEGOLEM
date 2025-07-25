#ifndef PLAYCARD_h
#define PLAYCARD_h

#include "action.h"
#include "../game.h"
#include "../minion.h"
class PlayCard: public Action {

  int cardID;
  public:
    PlayCard(int cardID): cardID(cardID) {}
    void execute(Game& game) {
      auto &player = game.getActivePlayer();
      auto &hand = player.getHand();
      auto &board = player.getBoard();
      board.addCard(std::move(hand.extractCard(cardID)));
      std::cout << "played card" << std::to_string(cardID) << std::endl;
    };
};

#endif // PLAYCARD_h