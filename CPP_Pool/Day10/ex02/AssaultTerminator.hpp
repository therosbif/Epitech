/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD10-jack.goodall
** File description:
** AssaultTerminator
*/

#ifndef ASSAULTTERMINATOR_HPP_
#define ASSAULTTERMINATOR_HPP_

#include "ISpaceMarine.hpp"
#include <iostream>

class AssaultTerminator : public ISpaceMarine {
    public:
        AssaultTerminator();
        ~AssaultTerminator();

        ISpaceMarine *clone() const;
        void battleCry() const { std::cout << "This code is unclean. PURIFY IT!" << std::endl; };
        void rangedAttack() const { std::cout << "* does nothing *" << std::endl; };
        void meleeAttack() const { std::cout << "* attacks with chainfists *" << std::endl; };

    protected:
    private:
};

#endif /* !ASSAULTTERMINATOR_HPP_ */
