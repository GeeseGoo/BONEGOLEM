#include "asciiinterpreter.h"
#include "ascii_graphics.h"
#include "../minions/minion.h"
#include "../hand.h"
#include "../board.h"
#include "../card.h"
#include <ostream>
using namespace std;

// helper function for calling correct display function from ascii_graphics
card_template_t makeCardDisplay(Card* card){
    if(card->getTopLeft() != "" && card->getBottomLeft() != "" && card->getBottomRight() != ""){
        return display_tl_bl_br_card(card->getName(), card->getCost(), card->getType(), card->description(), card->getTopLeft(), card->getBottomLeft(), card->getBottomRight());
    }else if(card->getBottomLeft() != "" && card->getBottomRight() != ""){
        return display_bl_br_card(card->getName(), card->getCost(), card->getType(), card->description(), card->getBottomLeft(), card->getBottomRight());
    }else if(card->getTopLeft() != "" && card->getBottomRight() != ""){
        return display_tl_br_card(card->getName(), card->getCost(), card->getType(), card->description(), card->getTopLeft(), card->getBottomRight());
    }else{
        return display_basic_card(card->getName(), card->getCost(), card->getType(), card->description());
    }
}

void AsciiInterpreter::displayMinion(int index){
    Minion* minion = game->getActivePlayer().getBoard().getMinion(index);
    card_template_t output = makeCardDisplay(minion);
    for(string line : output){
        cout << line << endl;
    }
    // should display enchantments here
}

void AsciiInterpreter::displayHand(){
    // Card& card = game->getPlayers().getHand().getCard(0);
    cout << "Hand moment" << endl;
}

void AsciiInterpreter::displayBoard(){
    cout << "Board moment" << endl;
}
