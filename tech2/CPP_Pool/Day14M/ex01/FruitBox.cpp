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
        next = tmp->next;
        delete tmp;
        tmp = next;
    }
}

int FruitBox::nbFruits() const
{
    FruitNode *tmp = _list;
    int i = 0;

    for (; tmp != nullptr; i++) tmp = tmp->next;
    return i;
}

bool FruitBox::putFruit(Fruit *f)
{
    FruitNode *tmp = _list;

    if (nbFruits() == _size) return false;
    if (tmp == nullptr){
        _list = new FruitNode(f);
        return true;
    }
    while (tmp->next != nullptr) {
        if (tmp->_fruit == f) return false;
        tmp = tmp->next;
    }
    if (tmp->_fruit == f) return false;
    tmp->next = new FruitNode(f);
    return true;
}

Fruit *FruitBox::pickFruit()
{
    Fruit *first = _list->_fruit;
    FruitNode *my_next = _list->next;

    _list = my_next;
    return first;
}
