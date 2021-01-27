/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush2-jack.goodall
** File description:
** Teddy
*/

#include "Teddy.hpp"

Teddy::Teddy(const std::string &title) : Toy(title, "Teddy")
{
}

Teddy::~Teddy()
{
}

Toy *Teddy::isTaken()
{
    std::cout << "gra hu" << std::endl;
    _taken = true;
    return this;
}
