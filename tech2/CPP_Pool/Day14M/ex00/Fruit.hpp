/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD14M-jack.goodall
** File description:
** Fruit
*/

#ifndef FRUIT_HPP_
#define FRUIT_HPP_

#include <string>
#include <iostream>

class Fruit {
    public:
        Fruit(const std::string &name, int vitamins) : _name(name), _vitamins(vitamins) {};
        Fruit(Fruit &) = default;
        virtual ~Fruit();
        Fruit &operator=(const Fruit &) = default;

        virtual const std::string &getName() const = 0;
        int getVitamins() const { return _vitamins; };

    protected:
        std::string _name;
    private:
        int _vitamins;
};

#endif /* !FRUIT_HPP_ */
