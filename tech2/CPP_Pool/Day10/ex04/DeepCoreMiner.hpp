/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD10-jack.goodall
** File description:
** DeepCoreMiner
*/

#ifndef DEEPCOREMINER_HPP_
#define DEEPCOREMINER_HPP_

#include "IMiningLaser.hpp"
#include "IAsteroid.hpp"
#include <iostream>

class DeepCoreMiner : public IMiningLaser {
    public:
        DeepCoreMiner();
        ~DeepCoreMiner();

        void mine(IAsteroid *);

    protected:
    private:
};

#endif /* !DEEPCOREMINER_HPP_ */
