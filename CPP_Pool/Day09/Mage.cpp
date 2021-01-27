/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD09-jack.goodall
** File description:
** Mage
*/

#include "Mage.hpp"

Mage::Mage(const std::string &name, int lvl) : Character(name, lvl)
{
    _strength = 6;
    _stamina = 6;
    _intelligence = 12;
    _spirit = 11;
    _agility = 7;
    std::cout << name << " teleported" << std::endl;
}

int Mage::CloseAttack(void)
{
    if (Range == RANGE) return 0;
    if (_power < 10) {
        std::cout << getName() << " out of power" << std::endl;
        return 0;
    }
    _power -= 10;
    std::cout << getName() << " blinks" << std::endl;
    Range = RANGE;
    return 0;
}

int Mage::RangeAttack()
{
    if (_power < 25) {
        std::cout << getName() << " out of power" << std::endl;
        return 0;
    }
    _power -= 25;
    std::cout << getName() << " launches a fire ball" << std::endl;
    Range = CLOSE;
    return (20 + _spirit);
}

void Mage::RestorePower()
{
    _power += MIN(50 + _intelligence, 100 - _power);
    std::cout << getName() << " takes a mana potion" << std::endl;
}

void Mage::Heal()
{
    Character::Heal();
}
