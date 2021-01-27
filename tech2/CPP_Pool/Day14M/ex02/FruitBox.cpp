/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD14M-jack.goodall
** File description:
** FruitBox
*/

#include "FruitBox.hpp"

FruitBox::FruitBox(int size) : _size(size), _list(nullptr)
{
}

FruitBox::~FruitBox()
{
    FruitNode *tmp = _list;
    FruitNode *next = nullptr;

    while (tmp) {
        next = tmp->_next;
        delete tmp;
        tmp = next;
    }
}

int FruitBox::nbFruits() const
{
    FruitNode *tmp = _list;
    int i = 0;

    for (; tmp != nullptr; i++) tmp = tmp->_next;
    return i;
}

bool FruitBox::putFruit(const Fruit *f)
{
    FruitNode *tmp = _list;

    if (nbFruits() == _size) return false;
    if (tmp == nullptr){
        _list = new FruitNode(f);
        return true;
    }
    while (tmp->_next != nullptr) {
        if (tmp->_fruit == f) return false;
        tmp = tmp->_next;
    }
    if (tmp->_fruit == f) return false;
    tmp->_next = new FruitNode(f);
    return true;
}

const Fruit *FruitBox::pickFruit()
{
    const Fruit *first = _list->_fruit;
    FruitNode *next = _list->_next;

    _list = next;
    return first;
}
