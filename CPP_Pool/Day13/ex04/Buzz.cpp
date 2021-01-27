/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD13-jack.goodall
** File description:
** Buzz
*/

#include "Buzz.hpp"

Buzz::Buzz(const std::string &name, const std::string &file) : Toy(BUZZ, name, file)
{
}

Buzz::~Buzz()
{
}

void Buzz::speak(const std::string &text)
{
    std::cout << "BUZZ: " << getName() << " \"" << text << "\"" << std::endl;
}
