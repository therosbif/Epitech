/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD10-jack.goodall
** File description:
** DeepCoreMiner
*/

#include "DeepCoreMiner.hpp"

DeepCoreMiner::DeepCoreMiner()
{
}

DeepCoreMiner::~DeepCoreMiner()
{
}

void DeepCoreMiner::mine(IAsteroid *asteroid)
{
    std::cout << "* mining  deep ... got " << asteroid->beMined(this) << "! *" << std::endl;
}
