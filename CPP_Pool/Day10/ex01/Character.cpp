/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD10-jack.goodall
** File description:
** Character
*/

#include "Character.hpp"

Character::Character(const std::string &name) : _name(name), _ap(40), _weapon(nullptr)
{
}

Character::~Character()
{
}

void Character::attack(AEnemy *enemy)
{
    if (_weapon->getAPCost() > _ap || _weapon == nullptr) return;
    std::cout << _name << " attacks " << enemy->getType() << " with a " << _weapon->getName() << std::endl;
    _ap -= _weapon->getAPCost();
    _weapon->attack();
    enemy->takeDamage(_weapon->getDamage());
    if (enemy->getHP() <= 0)
        delete enemy;
}

std::ostream &operator<<(std::ostream &out, Character &character)
{
    out << character.getName() << " has " << character.getAP() << " AP and ";
    if (character.isArmed())
        out << "wields a " << character.getWeapon()->getName();
    else
        out << "is unarmed";
    out << std::endl;
    return out;
}
