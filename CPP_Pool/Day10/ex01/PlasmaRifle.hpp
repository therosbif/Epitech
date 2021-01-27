/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD10-jack.goodall
** File description:
** PlasmaRifle
*/

#ifndef PLASMARIFLE_HPP_
#define PLASMARIFLE_HPP_

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon {
    public:
        PlasmaRifle();
        ~PlasmaRifle();

        void attack() const;

    protected:
    private:
};

#endif /* !PLASMARIFLE_HPP_ */
