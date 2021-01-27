/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD16-jack.goodall
** File description:
** Ratatouille
*/

#include "Ratatouille.hpp"

Ratatouille &Ratatouille::addVegetable(unsigned char c)
{
    _pot << c;
    return *this;
}

Ratatouille &Ratatouille::addCondiment(unsigned int i)
{
    _pot << i;
    return *this;
}

Ratatouille &Ratatouille::addSpice(double c)
{
    _pot << c;
    return *this;
}

Ratatouille &Ratatouille::addSauce(const std::string &c)
{
    _pot << c;
    return *this;
}

Ratatouille &Ratatouille::operator=(const Ratatouille &r)
{
    _pot.str(std::string());
    _pot << r.kooc();
    return *this;
}
