/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD09-jack.goodall
** File description:
** Hunter
*/

#ifndef HUNTER_HPP_
#define HUNTER_HPP_

#include "Warrior.hpp"

class Hunter : public Warrior {
    public:
        Hunter(const std::string &name, int lvl);

        int CloseAttack();
        int RangeAttack();
        void Heal();
        void RestorePower();

    protected:
    private:
};

#endif /* !HUNTER_HPP_ */
