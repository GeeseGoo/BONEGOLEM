#include "controller.h"
#include <iostream>
#include <fstream>
using namespace std;


int main (int argc, char* argv[]) {
    Controller c;
    string initFile;
    string deck1, deck2;
    for (int i = 1; i < argc; i++) {
        if (string(argv[i]) == "-init") {
            initFile = argv[++i];
        }
    }

    if(!initFile.empty()) {
            ifstream fin(initFile);
            c.play(fin, true);
            c.play(cin, false);
    }
    else {
        c.play(cin, true);

    }
}
