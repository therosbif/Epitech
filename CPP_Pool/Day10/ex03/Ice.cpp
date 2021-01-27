/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD10-jack.goodall
** File description:
** Ice
*/

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::~Ice()
{
}

AMateria *Ice::clone() const
{
    AMateria *my_clone = new Ice();

    return my_clone;
}

void Ice::use(ICharacter &target)
{
    AMateria::use(target);
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
