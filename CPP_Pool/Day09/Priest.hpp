/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD09-jack.goodall
** File description:
** Priest
*/

#ifndef PRIEST_HPP_
#define PRIEST_HPP_

#include "Mage.hpp"

class Priest : public Mage {
    public:
        Priest(const std::string &name, int lvl);

        int CloseAttack();
        int RangeAttack();
        void Heal();
        void RestorePower();

    protected:
    private:
};

#endif /* !PRIEST_HPP_ */
