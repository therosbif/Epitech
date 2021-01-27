/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD09-jack.goodall
** File description:
** Character
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <iostream>

#define MIN(x, y) ((x < y) ? x : y)

class Character {
    public:
        Character(const std::string &, int);

        const std::string &getName() const { return _name; };
        int getLvl() const { return _level; };
        int getPv() const { return _health; };
        int getPower() const { return _power; };

        typedef enum AttackRange_e { CLOSE, RANGE } AttackRange;
        int Range;

        int CloseAttack();
        void Heal();
        int RangeAttack();
        void RestorePower();

        void TakeDamage(int);

    protected:
        int _stamina;
        int _spirit;
        int _agility;
        int _strength;
        int _intelligence;
        int _power;
        int _health;

    private:
        const std::string _name;
        int _level;
};

#endif /* !CHARACTER_HPP_ */
