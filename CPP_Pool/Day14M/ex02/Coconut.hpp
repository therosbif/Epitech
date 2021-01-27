/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD14M-jack.goodall
** File description:
** Coconut
*/

#ifndef COCONUT_HPP_
#define COCONUT_HPP_

#include "Fruit.hpp"

class Coconut : public Fruit {
    public:
        Coconut();
        ~Coconut();

        const std::string &getName() const { return _name; };

    protected:
    private:
};

#endif /* !COCONUT_HPP_ */
