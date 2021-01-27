/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD07A-jack.goodall
** File description:
** Skat
*/

#include "Skat.hpp"

Skat::Skat(const std::string &name, int stimpaks) : _name(name), _stimPaks(stimpaks)
{
}

Skat::~Skat()
{
}

int &Skat::stimPaks(void)
{
    return _stimPaks;
}

void Skat::stimPaks(int &stimpaks)
{
    _stimPaks = stimpaks;
}

const std::string &Skat::name(void)
{
    return _name;
}

void Skat::shareStimPaks(int number, int &stock)
{
    if (_stimPaks - number >= 0) {
        stock += number;
        _stimPaks -= number;
        std::cout << "Keep the change." << std::endl;
    } else
        std::cout << "Don't be greedy" << std::endl;
}

void Skat::addStimPaks(unsigned int number)
{
    _stimPaks += number;
    if (!number)
        std::cout << "Hey boya, did you forget something?" << std::endl;
}

void Skat::useStimPaks(void)
{
    if (_stimPaks > 0) {
        _stimPaks--;
        std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
    } else
        std::cout << "Mediiiiiic" << std::endl;
}

void Skat::status(void) const
{
    std::cout << "Soldier " << _name << " reporting " << _stimPaks << " stimpaks remaining sir!" << std::endl;
}
