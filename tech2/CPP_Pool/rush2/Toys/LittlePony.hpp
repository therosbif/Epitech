/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush2-jack.goodall
** File description:
** LittlePony
*/

#ifndef LITTLEPONY_HPP_
#define LITTLEPONY_HPP_

#include "Toy.hpp"

class LittlePony : public Toy {
    public:
        LittlePony(const std::string &title);
        ~LittlePony();

        Toy *isTaken() final;

    protected:
    private:
};

#endif /* !LITTLEPONY_HPP_ */
