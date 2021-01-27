/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD10-jack.goodall
** File description:
** TacticalMarine
*/

#ifndef TACTICALMARINE_HPP_
#define TACTICALMARINE_HPP_

#include "ISpaceMarine.hpp"
#include <iostream>

class TacticalMarine : public ISpaceMarine {
    public:
        TacticalMarine();
        ~TacticalMarine();

        ISpaceMarine *clone() const;
        void battleCry() const { std::cout << "For the holy PLOT!" << std::endl; };
        void rangedAttack() const { std::cout << "* attacks with bolter *" << std::endl; };
        void meleeAttack() const { std::cout << "* attacks with chainsword *" << std::endl; };

    protected:
    private:
};

#endif /* !TACTICALMARINE_HPP_ */
