/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD14M-jack.goodall
** File description:
** Lemon
*/

#ifndef LEMON_HPP_
#define LEMON_HPP_

#include "Fruit.hpp"

class Lemon : public Fruit {
    public:
        Lemon() : Fruit("lemon", 3) {};
        ~Lemon();

        const std::string &getName() const { return _name; };

    protected:
    private:
};

#endif /* !LEMON_HPP_ */
