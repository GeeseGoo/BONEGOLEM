#include "lib.h"
#include "minions/minion.h"
#include "spells/spell.h"
#include "rituals/ritual.h"
#include "enchantments/enchantment.h"
#include "board.h"

void Board::addCard(Minion *minion)
{
    if (minions.size() < 5)
        minions.emplace_back(std::unique_ptr<Minion>(minion));
}
void Board::addCard(Ritual *r)
{
    ritual = std::unique_ptr<Ritual>(r);
}
Minion *Board::getMinion(int i)
{
    if (minions.size() <= 0)
        throw std::runtime_error("empty board");
    if (i < 0 || i >= minions.size() || !(minions.at(i)))
    {
        throw std::runtime_error("no minion at index: " + std::to_string(i));
    }
    return minions.at(i).get();
}

void Board::trigger(Action *action, Game &game)
{
    cout << "Cecking triggers" << endl;
    for (Minion *m : getMinions())
    {
        if (m && m->getTrigger())
            m->getTrigger()->trigger(action, *this, game);
    }
    if (ritual && ritual->getTrigger())
        ritual->getTrigger()->trigger(action, *this, game);
}

std::vector<Minion *> Board::getMinions()
{
    std::vector<Minion *> result;
    for (const auto &ptr : minions)
    {
        result.push_back(ptr.get());
    }
    return result;
}

Minion *Board::attach(Enchantment *newEnchantment, int index)
{
    Minion *old = minions.at(index).release();
    minions.at(index) = std::unique_ptr<Enchantment>(newEnchantment);
    return old;
}

void Board::detach(int index)
{
    if (!minions.at(index)->isEnchantment())
        return;
    minions[index] = unique_ptr<Minion>(minions.at(index)->extractNext());
}

void Board::detachAll(int index)
{
    while (minions.at(index)->isEnchantment())
    {
        std::cout << "removing enchantment: " << minions.at(index)->getName() << std::endl;
        detach(index);
    }
}

void Board::removeMinion(Minion &minion)
{
    for (int i = 0; i < minions.size(); ++i)
    {
        if (minions[i]->getBase() == &minion)
        {
            detachAll(i);
            minions[i].release();
            minions.erase(minions.begin() + i);
            return;
        }
    }
    throw std::runtime_error("Minion not found to be erased");
}