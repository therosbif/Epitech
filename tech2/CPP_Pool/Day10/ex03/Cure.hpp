/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD10-jack.goodall
** File description:
** Cure
*/

#ifndef CURE_HPP_
#define CURE_HPP_

#include "AMateria.hpp"

class Cure : public AMateria {
    public:
        Cure();
        ~Cure();

        AMateria *clone() const;
        void use(ICharacter &target);

    protected:
    private:
};

#endif /* !CURE_HPP_ */
