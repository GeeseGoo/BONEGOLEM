#ifndef CARD_h
#define CARD_h
#include <string>
class Card {
  std::string name;
  std::string desc;
  
  public:
    Card(std::string name): name(name) {};
};


#endif // CARD_h