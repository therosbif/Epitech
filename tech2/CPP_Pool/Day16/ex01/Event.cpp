/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD16-jack.goodall
** File description:
** Event
*/

#include "Event.hpp"

Event::Event(unsigned int time, const std::string &event) : _time(time), _event(event)
{
}

Event::Event(const Event &e)
{
    _time = e.getTime();
    _event = e.getEvent();
}
