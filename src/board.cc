#include "lib.h"
#include "minions/minion.h"
#include "spells/spell.h"
#include "rituals/ritual.h"
#include <string>
#include <stdexcept>
#include "board.h"

void Board::addCard(Minion *minion)
{
    minions.emplace_back(std::unique_ptr<Minion>(minion));
}
void Board::addCard(Ritual *r)
{
    ritual = std::unique_ptr<Ritual>(r);
}
Minion *Board::getMinion(int i)
{
    if (minions.size() <= i)
        throw std::runtime_error("empty board");
    if (!(minions.at(i)))
    {
        throw std::runtime_error("no minion at index" + std::to_string(i));
    }
    return minions.at(i).get();
}

void Board::addTrigger(Trigger *trigger)
{
    triggers.emplace_back(trigger);
}

void Board::notifyStartTurnTriggers(StartTurn *action, Board &board, Game &game)
{
    for (auto trigger : triggers)
    {
        if (trigger)
        {

            trigger->beTriggered(action, *this, game);
        }
    }
}

void Board::notifyEndTurnTriggers(EndTurn *action, Board &board, Game &game)
{
    for (auto trigger : triggers)
    {
        if (trigger)
        {

            trigger->beTriggered(action, *this, game);
        }
    }
}
void Board::notifyEnterPlayTriggers(PlayCard *action, Board &board, Game &game)
{
    for (auto trigger : triggers)
    {
        if (trigger)
        {
            trigger->beTriggered(action, *this, game);
        }
    }
}
void Board::notifyLeavePlayTriggers(LeavePlay *action, Board &board, Game &game)
{
    for (auto trigger : triggers)
    {
        if (trigger)
        {

            trigger->beTriggered(action, *this, game);
        }
    }
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
