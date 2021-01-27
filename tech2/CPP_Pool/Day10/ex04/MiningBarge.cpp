/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD10-jack.goodall
** File description:
** MiningBarge
*/

#include "MiningBarge.hpp"

MiningBarge::MiningBarge()
{
    for (int i = 0; i < 4; i++)
        _laser[i] = nullptr;
}

MiningBarge::~MiningBarge()
{
}

void MiningBarge::equip(IMiningLaser *laser)
{
    int i = 0;

    for (; i < 4 && _laser[i] != nullptr; i++);
    if (i == 4) return;
    _laser[i] = laser;
}

void MiningBarge::mine(IAsteroid *asteroid) const
{
    for (int i = 0; i < 4; i++)
        if (_laser[i] != nullptr)
            _laser[i]->mine(asteroid);
}
