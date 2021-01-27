/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD10-jack.goodall
** File description:
** AsteroKreog
*/

#ifndef ASTEROKREOG_HPP_
#define ASTEROKREOG_HPP_

#include "IAsteroid.hpp"
#include "DeepCoreMiner.hpp"
#include "StripMiner.hpp"

class AsteroKreog : public IAsteroid {
    public:
        AsteroKreog();
        ~AsteroKreog();

        std::string beMined (DeepCoreMiner *) const;
        std::string beMined (StripMiner *) const;
        std::string getName() const { return _name; };

    protected:
    private:
        std::string _name;
};

#endif /* !ASTEROKREOG_HPP_ */
