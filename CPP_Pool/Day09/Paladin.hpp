/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD09-jack.goodall
** File description:
** Paladin
*/

#ifndef PALADIN_HPP_
#define PALADIN_HPP_

#include "Warrior.hpp"
#include "Priest.hpp"

class Paladin : public Warrior, public Priest {
    public:
        Paladin(const std::string &name, int lvl);

        int CloseAttack();
        int RangeAttack();
        void Heal();
        void RestorePower();
        int Intercept();

    protected:
    private:
};

#endif /* !PALADIN_HPP_ */
