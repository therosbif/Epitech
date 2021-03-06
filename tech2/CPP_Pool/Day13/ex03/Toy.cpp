/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD13-jack.goodall
** File description:
** Toy
*/

#include "Toy.hpp"

Toy::Toy() : _picture(Picture()), _type(BASIC_TOY), _name("toy")
{
}

Toy::Toy(int toyType, const std::string &name, const std::string &file) : _picture(Picture(file)), _type(toyType), _name(name)
{
}

Toy::~Toy()
{
}

void Toy::speak(const std::string &text)
{
    std::cout << _name << " \"" << text << "\"" << std::endl;
}
