/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD07M-jack.goodall
** File description:
** Borg
*/

#ifndef BORG_HPP_
#define BORG_HPP_

#include "WarpSystem.hpp"
#include "Destination.hpp"
//#include "Federation.hpp"

namespace Federation
{
    class Ship;
    namespace Starfleet
    {
        class Ship;
    }
}

namespace Borg {
    class Ship {
        public:
            Ship(int weaponFrequency = 20, short repair = 3);
            ~Ship();

            void setupCore(WarpSystem::Core *);
            void checkCore();
            bool move(int, Destination);
            bool move(int);
            bool move(Destination d);
            bool move();
            int getShield();
            void setShield(int);
            int getWeaponFrequency();
            void setWeaponFrequency(int);
            int getRepair();
            void setRepair(int);
            void fire(Federation::Starfleet::Ship *target);
            void fire(Federation::Ship *target);
            void repair();
        private:
            int _side;
            short _maxWarp;
            WarpSystem::Core *_core;
            Destination _home;
            Destination _location;
            int _shield;
            int _weaponFrequency;
            short _repair;
    };
}

#endif /* !BORG_HPP_ */
