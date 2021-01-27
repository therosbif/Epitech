/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD07A-jack.goodall
** File description:
** Parts
*/

#include "Parts.hpp"

Arms::Arms(const std::string &serial, bool functional) : _serial(serial), _functional(functional)
{
}

Arms::~Arms()
{
}

bool Arms::isFunctional() const
{
    return _functional;
}

std::string Arms::serial() const
{
    return _serial;
}

void Arms::informations() const
{
    std::cout << "\t[Parts] Arms " << _serial << " status : " << (_functional ? "OK" : "KO") << std::endl;
}




Legs::Legs(const std::string &serial, bool functional) : _serial(serial), _functional(functional)
{
}

Legs::~Legs()
{
}

bool Legs::isFunctional() const
{
    return _functional;
}

std::string Legs::serial() const
{
    return _serial;
}

void Legs::informations() const
{
    std::cout << "\t[Parts] Legs " << _serial << " status : " << (_functional ? "OK" : "KO") << std::endl;
}




Head::Head(const std::string &serial, bool functional) : _serial(serial), _functional(functional)
{
}

Head::~Head()
{
}

bool Head::isFunctional() const
{
    return _functional;
}

std::string Head::serial() const
{
    return _serial;
}

void Head::informations() const
{
    std::cout << "\t[Parts] Head " << _serial << " status : " << (_functional ? "OK" : "KO") << std::endl;
}
