/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD07M-jack.goodall
** File description:
** Admiral
*/

#include "Admiral.hpp"

Federation::Starfleet::Admiral::Admiral(std::string name) : _name(name)
{
    movePtr = &Federation::Starfleet::Ship::move;
    firePtr = &Federation::Starfleet::Ship::fire;
    std::cout << "Admiral " << _name << " ready for action." << std::endl;
}

Federation::Starfleet::Admiral::~Admiral()
{
}

void Federation::Starfleet::Admiral::fire(Federation::Starfleet::Ship *ship, Borg::Ship *target)
{
    std::cout << "On order from Admiral " << _name << ":" << std::endl;
    (*ship.*firePtr)(target);
}

bool Federation::Starfleet::Admiral::move(Federation::Starfleet::Ship *ship, Destination dest)
{
    return (*ship.*movePtr)(dest);
}
