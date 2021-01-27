/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD10-jack.goodall
** File description:
** Victim
*/

#include "Victim.hpp"

Victim::Victim(const std::string &name) : _name(name)
{
    std::cout << "Some random victim called " << _name << " just popped!" << std::endl;
}

Victim::~Victim()
{
    std::cout << "Victim " << _name << " just died for no apparent reason!" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Victim &victim)
{
    out << "I'm " << victim.getName() << " and I like otters!" << std::endl;
    return out;
}

void Victim::getPolymorphed() const
{
    std::cout << _name << " has been turned into a cute little sheep!" << std::endl;
}
