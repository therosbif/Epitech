/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD14M-jack.goodall
** File description:
** LittleHand
*/

#include "LittleHand.hpp"

LittleHand::LittleHand()
{
}

LittleHand::~LittleHand()
{
}

void LittleHand::sortFruitBox(FruitBox &unsorted, FruitBox &lemons,
    FruitBox &bananas, FruitBox &limes)
{
    std::string type;
    Fruit *holding;

    while (unsorted.nbFruits() > 0) {
        holding = unsorted.pickFruit();
        if (holding->getName() == "lemon") {
            if (!lemons.putFruit(holding)) unsorted.putFruit(holding);
        } else if (holding->getName() == "lime") {
            if (!limes.putFruit(holding)) unsorted.putFruit(holding);
        } else if (holding->getName() == "banana") {
            if (!bananas.putFruit(holding)) unsorted.putFruit(holding);
        }
    }
}
