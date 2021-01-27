/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD09-jack.goodall
** File description:
** Priest
*/

#include "Priest.hpp"

Priest::Priest(const std::string &name, int lvl) : Character(name, lvl), Mage(name, lvl)
{
    _strength = 4;
    _stamina = 4;
    _intelligence = 42;
    _spirit = 21;
    _agility = 2;
    std::cout << getName() << " enters in the order" << std::endl;
}

int Priest::CloseAttack(void)
{
    if (Range == RANGE) return 0;
    if (_power < 10) {
        std::cout << getName() << " out of power" << std::endl;
        return 0;
    }
    _power -= 10;
    std::cout << getName() << " uses a spirit explosion" << std::endl;
    Range = RANGE;
    return (10 + _spirit);
}

void Priest::Heal()
{
    if (_power < 10) {
        std::cout << getName() << " out of power" << std::endl;
        return;
    }
    _power -= 10;
    _health += MIN(70, 100 - _health);
    std::cout << getName() << " casts a little heal spell" << std::endl;
}

int Priest::RangeAttack()
{
    return Mage::RangeAttack();
}

void Priest::RestorePower()
{
    Mage::RestorePower();
}
