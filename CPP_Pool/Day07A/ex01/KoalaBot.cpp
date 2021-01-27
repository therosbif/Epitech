/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD07A-jack.goodall
** File description:
** KoalaBot
*/

#include "KoalaBot.hpp"

KoalaBot::KoalaBot(const std::string &serial) : _serial(serial)
{
}

KoalaBot::~KoalaBot()
{
}

void KoalaBot::setParts(Arms const &arms)
{
    _arms = arms;
}

void KoalaBot::setParts(Legs const &legs)
{
    _legs = legs;
}

void KoalaBot::setParts(Head const &head)
{
    _head = head;
}

void KoalaBot::swapParts(Arms &arms)
{
    Arms tmp = _arms;

    _arms = arms;
    arms = tmp;
}

void KoalaBot::swapParts(Legs &legs)
{
    Legs tmp = _legs;

    _legs = legs;
    legs = tmp;
}

void KoalaBot::swapParts(Head &head)
{
    Head tmp = _head;

    _head = head;
    head = tmp;
}

void KoalaBot::informations(void) const
{
    std::cout << "[KoalaBot] " << _serial << std::endl;
    _arms.informations();
    _legs.informations();
    _head.informations();
}

bool KoalaBot::status(void) const
{
    return (_arms.isFunctional() && _legs.isFunctional() && _head.isFunctional());
}
