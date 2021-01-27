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
    FruitNode(const Fruit *fruit) : _fruit(fruit), _next(nullptr) {};

    const Fruit *_fruit;
    FruitNode *_next;
};

#endif /* !FRUITNODE_HPP_ */
