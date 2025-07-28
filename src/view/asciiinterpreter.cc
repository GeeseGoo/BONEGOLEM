#include "asciiinterpreter.h"
#include "ascii_graphics.h"
#include "../minions/minion.h"
#include "../hand.h"
#include "../board.h"
#include <ostream>
using namespace std;

void AsciiInterpreter::displayMinion(int index){
    Minion* minion = game->getActivePlayer().getBoard().getMinion(index);
    card_template_t output;
    if(minion->description() == ""){
        output = display_minion_no_ability(minion->getName(), minion->getCost(), minion->getAtk(), minion->getDef());
    }else if(minion->getTopLeft() == ""){
        output = display_minion_triggered_ability(minion->getName(), minion->getCost(), minion->getAtk(), minion->getDef(), minion->description());
    }else{
        output = display_minion_activated_ability(minion->getName(), minion->getCost(), minion->getAtk(), minion->getDef(), minion->getAbilityCost(), minion->description());
    }
    for(string line : output){
        cout << line << endl;
    }
}

void AsciiInterpreter::displayHand(){
    // Card& card = game->getPlayers().getHand().getCard(0);
    cout << "Hand moment" << endl;
}

void AsciiInterpreter::displayBoard(){
    cout << "Board moment" << endl;
}
