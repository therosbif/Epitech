/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD09-jack.goodall
** File description:
** Mage
*/

#ifndef MAGE_HPP_
#define MAGE_HPP_

#include "Character.hpp"

class Mage : virtual public Character {
    public:
        Mage(const std::string &name, int lvl);

        int CloseAttack();
        int RangeAttack();
        void RestorePower();
        void Heal();

    protected:
    private:
};

#endif /* !MAGE_HPP_ */
