/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush2-jack.goodall
** File description:
** Teddy
*/

#ifndef TEDDY_HPP_
#define TEDDY_HPP_

#include "Toy.hpp"

class Teddy : public Toy{
    public:
        Teddy(const std::string &title);
        ~Teddy();

        Toy *isTaken() final;
    protected:
    private:
};

#endif /* !TEDDY_HPP_ */
