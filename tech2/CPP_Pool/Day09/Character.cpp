/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD09-jack.goodall
** File description:
** Character
*/

#include "Character.hpp"

Character::Character(const std::string &name, int lvl) : Range(CLOSE), _stamina(5), _spirit(5),
            _agility(5), _strength(5), _intelligence(5), _power(100), _health(100), _name(name), _level(lvl)
{
    std::cout << _name << " Created" << std::endl;
}

int Character::CloseAttack(void)
{
    if (Range == RANGE) return 0;
    if (_power < 10) {
        std::cout << _name << " out of power" << std::endl;
        return 0;
    }
    _power -= 10;
    std::cout << _name << " strikes with a wooden stick" << std::endl;
    return (10 + _strength);
}

void Character::Heal()
{
    _health += MIN(50, 100 - _health);
    std::cout << _name << " takes a potion" << std::endl;
}

int Character::RangeAttack()
{
    if (_power < 10) {
        std::cout << _name << " out of power" << std::endl;
        return 0;
    }
    _power -= 10;
    std::cout << _name << " tosses a stone" << std::endl;
    return (5 + _strength);
}

void Character::RestorePower(void)
{
    _power = 100;
    std::cout << _name << " eats" << std::endl;
}

void Character::TakeDamage(int damage)
{
    _health -= damage;
    if (_health <= 0)
        std::cout << _name << " out of combat" << std::endl;
    else
        std::cout << _name << " takes " << damage << " damage" << std::endl;
}
