#include "asciiinterpreter.h"
#include "ascii_graphics.h"
#include "../minions/minion.h"
#include "../hand.h"
#include "../board.h"
#include <ostream>
using namespace std;

void AsciiInterpreter::displayMinion(int index){
    Minion* minion = game->getActivePlayer().getBoard().getMinion(index);
    card_template_t output = {""};
    cout << "Minionn moment: " << minion->getName() << endl;
    
}

void AsciiInterpreter::displayHand(){
    // Card& card = game->getActivePlayer().getHand().getCard(0);
    cout << "Hand moment" << endl;
}

void AsciiInterpreter::displayBoard(){
    cout << "Board moment" << endl;
}
