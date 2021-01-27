/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-jack.goodall
** File description:
** Hostname
*/

#include "Hostname.hpp"

Hostname::Hostname()
{
    refreshInfo();

    _active = 0;
    _position = 0;
}

Hostname::~Hostname()
{
}

void Hostname::refreshInfo()
{
    char hn[50];

    gethostname(hn, sizeof(hn));
    _hostname = hn;
    _user = std::string(getlogin());
}
