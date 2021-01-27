/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD10-jack.goodall
** File description:
** StripMiner
*/

#ifndef STRIPMINER_HPP_
#define STRIPMINER_HPP_

#include "IMiningLaser.hpp"
#include "IAsteroid.hpp"
#include <iostream>

class StripMiner : public IMiningLaser {
    public:
        StripMiner();
        ~StripMiner();

        void mine(IAsteroid *);

    protected:
    private:
};

#endif /* !STRIPMINER_HPP_ */
