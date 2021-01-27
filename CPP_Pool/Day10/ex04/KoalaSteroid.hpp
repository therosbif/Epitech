/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD10-jack.goodall
** File description:
** KoalaSteroid
*/

#ifndef KOALASTEROID_HPP_
#define KOALASTEROID_HPP_

#include "IAsteroid.hpp"
#include "DeepCoreMiner.hpp"
#include "StripMiner.hpp"

class KoalaSteroid : public IAsteroid {
    public:
        KoalaSteroid();
        ~KoalaSteroid();

        std::string beMined (DeepCoreMiner *) const;
        std::string beMined (StripMiner *) const;
        std::string getName() const { return _name; };

    protected:
    private:
        std::string _name;
};

#endif /* !KOALASTEROID_HPP_ */
