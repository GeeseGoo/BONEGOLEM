#include "controller.h"
#include <iostream>
#include <fstream>
using namespace std;


int main (int argc, char* argv[]) {
    Controller c;
    string initFile;
    string deck1, deck2 = "default.deck";
    for (int i = 1; i < argc; i++) {
        if (string(argv[i]) == "-init") {
            initFile = argv[++i];
        }
        if(string(argv[i]) == "-deck1") {
            deck1 = argv[++i];
        }
        if(string(argv[i]) == "deck2") {
            deck2 = argv[++i];
        }
    }

    // since we are in src and want deck files to be in outer file add ../
    deck1 = "../" + deck1;
    deck2 = "../" + deck2;

    if(!initFile.empty()) {
            ifstream fin(initFile);
            c.init(fin, deck1, deck2);
            c.play(fin);
            c.play(cin);
    }
    else {
        c.init(cin, deck1, deck2);
        c.play(cin);

    }
}
