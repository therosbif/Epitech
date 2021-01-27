/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD10-jack.goodall
** File description:
** Ice
*/

#ifndef ICE_HPP_
#define ICE_HPP_

#include "AMateria.hpp"

class Ice : public AMateria {
    public:
        Ice();
        ~Ice();

        AMateria *clone() const;
        void use(ICharacter &target);

    protected:
    private:
};

#endif /* !ICE_HPP_ */
