/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD09-jack.goodall
** File description:
** Hunter
*/

#include "Hunter.hpp"

Hunter::Hunter(const std::string &name, int lvl) : Character(name, lvl), Warrior(name, lvl, "sword")
{
    _strength = 9;
    _stamina = 9;
    _intelligence = 5;
    _agility = 25;
    std::cout << name << " is born from a tree" << std::endl;
}

int Hunter::CloseAttack()
{
    return Warrior::CloseAttack();
}

int Hunter::RangeAttack()
{
    if (_power < 25) {
        std::cout << getName() << " out of power" << std::endl;
        return 0;
    }
    _power -= 25;
    std::cout << getName() << " uses his bow" << std::endl;
    Range = CLOSE;
    return (20 + _agility);
}

void Hunter::Heal()
{
    Character::Heal();
}

void Hunter::RestorePower()
{
    _power = 100;
    std::cout << getName() << " meditates" << std::endl;
}
