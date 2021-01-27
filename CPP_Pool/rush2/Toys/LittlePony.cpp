/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush2-jack.goodall
** File description:
** LittlePony
*/

#include "LittlePony.hpp"

LittlePony::LittlePony(const std::string &title) : Toy(title, "LittlePony")
{
}

LittlePony::~LittlePony()
{
}

Toy *LittlePony::isTaken()
{
    std::cout << "yo man" << std::endl;
    _taken = true;
    return this;
}
