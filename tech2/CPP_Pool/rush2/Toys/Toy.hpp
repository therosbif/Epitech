/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush2-jack.goodall
** File description:
** Toy
*/

#ifndef TOY_HPP_
#define TOY_HPP_

#include "Object.hpp"

class Toy : public Object {
    public:
        Toy(const std::string &title, const std::string &type);
        ~Toy();

        virtual Toy *isTaken();

        std::string xml() final;
    protected:
    private:
};

#endif /* !TOY_HPP_ */
