/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD10-jack.goodall
** File description:
** MateriaSource
*/

#ifndef MATERIASOURCE_HPP_
#define MATERIASOURCE_HPP_

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
    public:
        MateriaSource();
        ~MateriaSource();

        AMateria * createMateria(std::string const & type);
        void learnMateria(AMateria *);

    protected:
    private:
        AMateria *_memory[4];
};

#endif /* !MATERIASOURCE_HPP_ */
