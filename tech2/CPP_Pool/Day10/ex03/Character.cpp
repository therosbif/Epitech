/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD10-jack.goodall
** File description:
** Character
*/

#include "Character.hpp"

Character::Character(const std::string &name) : _name(name)
{
    for (int i = 0; i < 4; i++)
        _holding[i] = nullptr;
}

Character::Character(Character &character) : _name(character.getName())
{
    for (int i = 0; i < 4; i++)
        delete _holding[i];
    for (int i = 0; i < 4; i++)
        _holding[i] = character.getHolding(i)->clone();
}

Character &Character::operator=(Character &character)
{
    for (int i = 0; i < 4; i++)
        delete _holding[i];
    for (int i = 0; i < 4; i++)
        _holding[i] = character.getHolding(i)->clone();
    _name = character.getName();
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
        delete _holding[i];
}

void Character::equip(AMateria* m)
{
    int i = 0;

    for (; _holding[i] != nullptr && i < 4; i++);
    if (i == 4) return;
    _holding[i] = m;
}

void Character::unequip(int idx)
{
    _holding[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target)
{
    if (_holding[idx] == nullptr) return;
    _holding[idx]->use(target);
}
