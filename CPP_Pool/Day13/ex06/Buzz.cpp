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

bool Buzz::speak(const std::string &text)
{
    std::cout << "BUZZ: " << getName() << " \"" << text << "\"" << std::endl;
    return true;
}

bool Buzz::speak_es(const std::string &text)
{
    std::cout << "BUZZ: " << getName() << " senorita \"" << text << "\" senorita" << std::endl;
    return true;
}
