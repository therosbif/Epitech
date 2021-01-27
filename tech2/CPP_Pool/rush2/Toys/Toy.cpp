/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush2-jack.goodall
** File description:
** Toy
*/

#include "Toy.hpp"

Toy::Toy(const std::string &title, const std::string &type) : Object(title, type)
{
}

Toy::~Toy()
{
}


Toy *Toy::isTaken()
{
    std::cout << "Ya trying ?" << std::endl;
    _taken = true;
    return this;
}

std::string Toy::xml()
{
    return "<" + this->getType() + ">\n"
    + "\t" + this->getTitle() + "\n</" + this->getType() + ">\n";
}