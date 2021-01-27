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
    const Fruit *holding;

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

static int countCoconuts(Coconut const *coconuts)
{
    int i = 0;

    for (; coconuts[i].getName() != ""; i++);
    return i;
}

FruitBox * const *LittleHand::organizeCoconut(Coconut const * const *coconuts)
{
    int size = (int)((float)countCoconuts(*coconuts) / (float)6 + 0.99);
    FruitBox **boxes = new FruitBox*[size + 1];

    for (int i = 0; i < size; i++)
        boxes[i] = new FruitBox(6);
    boxes[size] = nullptr;
    for (int i = 0; i < size; i++) {
        for (int j = 0; coconuts[i * 6 + j] && j < 6; j++)
            boxes[i]->putFruit(coconuts[i * 6 + j]);
    }
    return boxes;
}
