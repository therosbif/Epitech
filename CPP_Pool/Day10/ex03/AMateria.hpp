/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD10-jack.goodall
** File description:
** AMateria
*/

#ifndef AMATERIA_HPP_
#define AMATERIA_HPP_

#include <iostream>
#include "ICharacter.hpp"

class AMateria {
    public:
        AMateria(const std::string &type);
        virtual ~AMateria();

        const std::string &getType() const { return _type; }; // Returns the materia type
        unsigned int getXP () const { return xp_; }; // Returns the Materia's XP

        virtual AMateria *clone() const = 0;
        virtual void use(ICharacter &target) { xp_ += 10; };

    protected:
    private:
        unsigned int xp_;
        const std::string _type;
};

#endif /* !AMATERIA_HPP_ */
