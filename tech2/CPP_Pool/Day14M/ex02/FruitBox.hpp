/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD14M-jack.goodall
** File description:
** FruitBox
*/

#ifndef FRUITBOX_HPP_
#define FRUITBOX_HPP_

#include "FruitNode.hpp"

class FruitBox {
    public:
        FruitBox(int size);
        ~FruitBox();

        int nbFruits() const;

        bool putFruit(const Fruit *f);
        const Fruit *pickFruit();
        FruitNode *head() { return _list; };

    protected:
    private:
        int _size;
        FruitNode *_list;
};

#endif /* !FRUITBOX_HPP_ */
