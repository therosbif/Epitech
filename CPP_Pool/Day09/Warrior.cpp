/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD09-jack.goodall
** File description:
** Warrior
*/

#include "Warrior.hpp"

Warrior::Warrior(const std::string &name, int lvl, std::string weapon) : Character(name, lvl), _weapon(weapon)
{
    _strength = 12;
    _stamina = 12;
    _intelligence = 6;
    _agility = 7;
    std::cout << "I'm " << name << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" << std::endl;
}

int Warrior::CloseAttack(void)
{
    if (Range == RANGE) return 0;
    if (_power < 30) {
        std::cout << getName() << " out of power" << std::endl;
        return 0;
    }
    _power -= 30;
    std::cout << getName() << " strikes with his " << _weapon << std::endl;
    return (20 + _strength);
}

int Warrior::RangeAttack()
{
    if (Range == CLOSE) return 0;
    if (_power < 10) {
        std::cout << getName() << " out of power" << std::endl;
        return 0;
    }
    _power -= 10;
    std::cout << getName() << " intercepts" << std::endl;
    Range = CLOSE;
    return (0);
}
