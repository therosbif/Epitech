/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD10-jack.goodall
** File description:
** MiningBarge
*/

#ifndef MININGBARGE_HPP_
#define MININGBARGE_HPP_

#include "IMiningLaser.hpp"
#include "IAsteroid.hpp"

class MiningBarge {
    public:
        MiningBarge();
        ~MiningBarge();

        void equip(IMiningLaser *laser);
        void mine(IAsteroid *asteroid) const;

    protected:
    private:
        IMiningLaser *_laser[4];
};

#endif /* !MININGBARGE_HPP_ */
