/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD16-jack.goodall
** File description:
** EventManager
*/

#include "EventManager.hpp"

void EventManager::addEvent(const Event &e)
{
    if (e.getTime() < _time)
        return;
    for (auto i = _events.begin(); i != _events.end(); i++) {
        if (i->getTime() > e.getTime()) {
            i = _events.emplace(i, e);
            return;
        }
    }
    _events.push_back(e);
}

void EventManager::removeEventsAt(unsigned int time)
{
    for (auto i = _events.begin(); i != _events.end();) {
        if (i->getTime() == time) {
            i = _events.erase(i);
        } else i++;
    }
}

void EventManager::dumpEvents() const
{
    for (auto i : _events) {
        std::cout << i.getTime() << ": " << i.getEvent() << std::endl;
    }
}

void EventManager::dumpEventAt(unsigned int time) const
{
    for (auto i : _events) {
        if (i.getTime() == time) {
            std::cout << i.getTime() << ": " << i.getEvent() << std::endl;
        }
        if (i.getTime() > time) break;
    }
}

void EventManager::addTime(unsigned int time)
{
    for (auto i = _events.begin(); i != _events.end();) {
        if (i->getTime() > (_time + time)) break;
        std::cout << i->getEvent() << std::endl;
        i = _events.erase(i);
    }
    _time += time;
}

void EventManager::addEventList(std::list<Event> &events)
{
    for (auto i : events) {
        addEvent(i);
    }
}
