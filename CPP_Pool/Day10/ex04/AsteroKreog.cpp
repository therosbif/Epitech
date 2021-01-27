/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD10-jack.goodall
** File description:
** AsteroKreog
*/

#include "AsteroKreog.hpp"

AsteroKreog::AsteroKreog() : _name("AsteroKreog")
{
}

AsteroKreog::~AsteroKreog()
{
}

std::string AsteroKreog::beMined(DeepCoreMiner *miner) const
{
    return "Sullite";
}

std::string AsteroKreog::beMined(StripMiner *miner) const
{
    return "Kreogium";
}
