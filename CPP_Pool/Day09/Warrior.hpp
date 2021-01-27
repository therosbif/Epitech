/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD09-jack.goodall
** File description:
** Warrior
*/

#ifndef WARRIOR_HPP_
#define WARRIOR_HPP_

#include "Character.hpp"

class Warrior: virtual public Character {
    public:
        Warrior(const std::string &name, int lvl, std::string weapon = "hammer");

        int CloseAttack();
        int RangeAttack();

    protected:
    private:
        const std::string _weapon;
};

#endif /* !WARRIOR_HPP_ */
