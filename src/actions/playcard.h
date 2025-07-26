#ifndef PLAYCARD_h
#define PLAYCARD_h

#include "action.h"
#include "../game.h"
#include "../minions/minion.h"
#include "../lib.h"
class PlayCard: public Action {

  int cardID;
  public:
    PlayCard(int cardID): cardID(cardID) {}
    void execute(Game& game) {
      auto &player = game.getActivePlayer();
      auto &hand = player.getHand();
      auto card = hand.extractCard(cardID);
      card->play(game, std::move(card));
      std::cout << "played card" << std::to_string(cardID) << std::endl;
    };
};

#endif // PLAYCARD_h