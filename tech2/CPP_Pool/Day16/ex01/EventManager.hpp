/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD16-jack.goodall
** File description:
** EventManager
*/

#ifndef EVENTMANAGER_HPP_
#define EVENTMANAGER_HPP_

#include "Event.hpp"
#include <iostream>

class EventManager {
    public:
        EventManager() = default;
        ~EventManager() = default;
        EventManager(const EventManager &) = default;
        EventManager &operator=(const EventManager &) = default;

        void addEvent(const Event &);
        void removeEventsAt(unsigned int time);
        void dumpEvents() const;
        void dumpEventAt(unsigned int) const;

        void addTime(unsigned int time);
        void addEventList(std::list<Event> &events);

    protected:
    private:
        unsigned int _time;
        std::list<Event> _events;
};

#endif /* !EVENTMANAGER_HPP_ */
