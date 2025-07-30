#include "asciiinterpreter.h"
#include "ascii_graphics.h"
#include "../minions/minion.h"
#include "../hand.h"
#include "../board.h"
#include "../card.h"
#include <ostream>
using namespace std;

// helper function for calling correct display function from ascii_graphics
card_template_t makeCardDisplay(Card* const card){
    if(!card){
        return CARD_TEMPLATE_BORDER;
    }else if(card->getTopLeft() != "" && card->getBottomLeft() != "" && card->getBottomRight() != ""){
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
    if(game->getActivePlayer().getBoard().getMinions().size() <= index || game->getActivePlayer().getBoard().getMinion(index) == nullptr){
        cout << "No minion at that index."  << endl;
        return;
    }
    Minion* minion = game->getActivePlayer().getBoard().getMinion(index);
    card_template_t output = makeCardDisplay(minion);
    for(string line : output){
        cout << line << endl;
    }
    // should display enchantments here
}

void AsciiInterpreter::displayHand(){
    vector<card_template_t> output = {};
    Hand& hand = game->getActivePlayer().getHand();
    for(unsigned int i = 0; i < hand.numCards(); i++){
        output.push_back(makeCardDisplay(&hand.getCard(i)));
    }
    if(output.size() == 0){
        cout << "Hand is empty." << endl;
        return;
    }
    for(unsigned int i = 0; i < output.at(0).size(); i++){
        for(card_template_t card : output){
            cout << card.at(i);
        }
        cout << endl;
    }
}

void displayPlayer(Player& current, int index = -1){
    vector<card_template_t> topRow = {};
    topRow.push_back(makeCardDisplay(current.getBoard().getRitual()));
    topRow.push_back(CARD_TEMPLATE_EMPTY);
    topRow.push_back(display_player_card_given(index, current.getName(), current.getHp(), current.getMagic()));
    topRow.push_back(CARD_TEMPLATE_EMPTY);
    topRow.push_back(makeCardDisplay(current.getGraveyard().top()));
    for(unsigned int i = 0; i < topRow.at(0).size(); i++){
        cout << EXTERNAL_BORDER_CHAR_UP_DOWN;
        for(card_template_t card : topRow){
            cout << card.at(i);
        }
        cout << EXTERNAL_BORDER_CHAR_UP_DOWN << endl;
    }
    vector<card_template_t> bottomRow = {};
    vector<Minion*> minions = current.getBoard().getMinions();
    for(unsigned int i = 0; i < 5; i++){
        Card* card;
        if(minions.size() <= i){
            card = nullptr;
        }else{
            card = minions.at(i);
        }
        bottomRow.push_back(makeCardDisplay(card));
    }
    for(unsigned int i = 0; i < bottomRow.at(0).size(); i++){
        cout << EXTERNAL_BORDER_CHAR_UP_DOWN;
        for(card_template_t card : bottomRow){
            cout << card.at(i);
        }
        cout << EXTERNAL_BORDER_CHAR_UP_DOWN << endl;
    }
}

void displayGraphic(){
    for(string line : CENTRE_GRAPHIC){
        cout << line << endl;
    }
}

void AsciiInterpreter::displayBoard(){
    vector<Player>& players = game->getPlayers();
    cout << EXTERNAL_BORDER_CHAR_TOP_LEFT;
    for(int i = 0; i < 165; i++){
        cout << EXTERNAL_BORDER_CHAR_LEFT_RIGHT;
    }
    cout << EXTERNAL_BORDER_CHAR_TOP_RIGHT << endl;
    
    if(players.size() < 2){
        throw logic_error("Not enough players!");
    }
    
    displayPlayer(players.at(0));
    for(unsigned int i=1; i < players.size(); i++){
        displayGraphic();
        displayPlayer(players.at(i));
    }

    cout << EXTERNAL_BORDER_CHAR_BOTTOM_LEFT;
    for(int i = 0; i < 165; i++){
        cout << EXTERNAL_BORDER_CHAR_LEFT_RIGHT;
    }
    cout << EXTERNAL_BORDER_CHAR_BOTTOM_RIGHT << endl;
}
