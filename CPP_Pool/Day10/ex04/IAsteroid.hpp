/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD10-jack.goodall
** File description:
** IAsteroid
*/

#ifndef IASTEROID_HPP_
#define IASTEROID_HPP_

#include <iostream>

class DeepCoreMiner;
class StripMiner;

class IAsteroid {
    public:
        virtual ~IAsteroid () {}
        virtual std::string beMined (DeepCoreMiner *) const = 0;
        virtual std::string beMined (StripMiner *) const = 0;
        virtual std::string getName() const = 0;

    protected:
    private:
};

#endif /* !IASTEROID_HPP_ */
