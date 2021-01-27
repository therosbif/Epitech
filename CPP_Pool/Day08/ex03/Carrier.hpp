/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD08-jack.goodall
** File description:
** Carrier
*/

#ifndef CARRIER_HPP_
#define CARRIER_HPP_

#include <iostream>
#include "Droid.hpp"

class Carrier {
    public:
        Carrier(const std::string id = "");
        ~Carrier();

        std::string getId() const { return Id; };
        size_t getEnergy() const { return Energy; };
        size_t getAttack() const { return Attack; };
        size_t getToughness() const { return Toughness; };
        size_t getSpeed() const { return Speed; };

        void setId(std::string id) { Id = id; };
        void setEnergy(size_t energy) { Energy = energy; };
        void setSpeed(size_t speed) { Speed = speed; };

        Carrier &operator<<(Droid *&);
        Carrier &operator>>(Droid *&);
        Carrier &operator<<(Carrier &);
        Carrier &operator<<(size_t &);

        Droid *&operator[](const size_t);
        Carrier &operator~();
        bool operator()(const int, const int);
        int getNbDroids() const;
    protected:
    private:
        std::string Id;
        size_t Energy;
        const size_t Attack;
        const size_t Toughness;
        size_t Speed;
        Droid *Droids[5];
};

std::ostream &operator<<(std::ostream &, Carrier &);

#endif /* !CARRIER_HPP_ */
