#include "ritual.h"
#include "../card.h"
#include "../triggers/trigger.h"
#include "../game.h"
#include "../board.h"


void Ritual:: play(Game& game, std::unique_ptr<Card>&& self) {
      // add trigger to game
      game.addTrigger(this->getTrigger());
      
      Card* rawCard = self.release();
      rawCard->addToBoard(game.getActivePlayer().getBoard());
    };

    void Ritual:: addToBoard(Board& board) {
      board.addCard(this);
    }

Ritual::Ritual(std::string name, std::unique_ptr<Trigger> trigger): Card(name, std::move(trigger)) {};
