/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD14M-jack.goodall
** File description:
** Banana
*/

#ifndef BANANA_HPP_
#define BANANA_HPP_

#include "Fruit.hpp"

class Banana : public Fruit {
    public:
        Banana() : Fruit("banana", 5) {};
        ~Banana();

        const std::string &getName() const { return _name; };

    protected:
    private:
};

#endif /* !BANANA_HPP_ */
