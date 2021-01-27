/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD09-jack.goodall
** File description:
** Paladin
*/

#include "Paladin.hpp"

Paladin::Paladin(const std::string &name, int lvl) : Character(name, lvl), Warrior(name, lvl), Priest(name, lvl)
{
    _strength = 9;
    _stamina = 10;
    _intelligence = 10;
    _spirit = 10;
    _agility = 2;
    std::cout << "the light falls on " << getName() << std::endl;
}

int Paladin::CloseAttack()
{
    return Warrior::CloseAttack();
}

void Paladin::Heal()
{
    Priest::Heal();
}

int Paladin::RangeAttack()
{
    return Priest::RangeAttack();
}

void Paladin::RestorePower()
{
    Character::RestorePower();
}

int Paladin::Intercept()
{
    return Warrior::RangeAttack();
}
