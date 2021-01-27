/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD14M-jack.goodall
** File description:
** FruitNode
*/

#ifndef FRUITNODE_HPP_
#define FRUITNODE_HPP_

#include "Fruit.hpp"

struct FruitNode {
    FruitNode() = default;
    FruitNode(Fruit *fruit) : _fruit(fruit), next(nullptr) {};

    Fruit *_fruit;
    FruitNode *next;
};

#endif /* !FRUITNODE_HPP_ */
