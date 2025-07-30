#include "enchantment.h"
#include "../player.h"
#include "../actions/enterplay.h"

Enchantment::Enchantment(std::string name, int cost, int playerNum): Minion(name, cost, 0, 0, 0, playerNum) {}

std::string Enchantment::getTopLeft(){
    if(!next) return enchantmentTopLeft();
    return next->getTopLeft();
}

std::string Enchantment::getBottomLeft(){
    if(!next) return enchantmentBottomLeft();
    return next->getBottomLeft();
}

std::string Enchantment::getBottomRight(){
    if(!next) return enchantmentBottomRight();
    return next->getBottomRight();
}

std::string Enchantment::description() {
    if(!next) return enchantmentDescription();
    return next->description();
}

std::string Enchantment::enchantmentDescription() {
    return "";
}

int Enchantment::getCost() {
    if(next){
        return next->getCost();
    }else{
        return cost;
    }
}

std::string Enchantment::enchantmentTopLeft(){
    return "";
}

std::string Enchantment::enchantmentBottomLeft(){
    return "";
}

std::string Enchantment::enchantmentBottomRight(){
    return "";
}

int Enchantment::enchantmentCost(){
    return cost;
}


Minion* Enchantment::getNext(){
    return next.get();
}

void Enchantment::play(Game &game, Player &player, EnterPlay* action){
    int index = action->getOnto();
    next = std::unique_ptr<Minion>(player.getBoard().attach(this, index));
    std::cout << "Attached " << this->name << " onto " << this->getName() << std::endl; 
    onEquip();
}

std::string Enchantment::getName() {
    if(!next) return name;
    return next->getName();
}

void Enchantment::onEquip(){}
    
bool Enchantment::isEnchantment(){
    return true;
}

void Enchantment::takeDamage(int dmg){
    next->takeDamage(dmg);
}
int Enchantment::getAtk() const {
    return next->getAtk();
}
int Enchantment::getDef() const {
    return next->getDef();
}
void Enchantment::setAtk(int val) {
    next->setAtk(val);
}
void Enchantment::setDef(int val) {
    next->setDef(val);
}
int Enchantment::getActions() const {
    return next->getActions();
}
int Enchantment::getAbilityCost() const {
    return next->getAbilityCost();
}

std::string Enchantment::getType() {
    if(!next) return "Enchantment";
    return "Minion";
}
