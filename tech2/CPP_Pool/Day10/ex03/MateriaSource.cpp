/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD10-jack.goodall
** File description:
** MateriaSource
*/

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        _memory[i] = nullptr;
}

MateriaSource::~MateriaSource()
{
}

void MateriaSource::learnMateria(AMateria *materia)
{
    int i = 0;

    for (; _memory[i] != nullptr && i < 4; i++);
    if (i == 4) return;
    _memory[i] = materia;
}

AMateria *MateriaSource::createMateria(const std::string &type)
{
    int i = 0;

    for (; i < 4 && type != _memory[i]->getType(); i++);
    if (i == 4) return nullptr;
    return _memory[i]->clone();
}
