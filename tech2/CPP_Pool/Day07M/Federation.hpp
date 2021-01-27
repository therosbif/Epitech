/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD07M-jack.goodall
** File description:
** Federation
*/

#ifndef FEDERATION_HPP_
#define FEDERATION_HPP_

#include <iostream>
#include <string>
#include "WarpSystem.hpp"
#include "Destination.hpp"
#include "Borg.hpp"

namespace Federation
{
    class Ship {
        public:
            Ship(const int, const int, const std::string);
            ~Ship();

            void setupCore(WarpSystem::Core *);
            void checkCore();
            bool move(int, Destination);
            bool move(int);
            bool move(Destination d);
            bool move();
            WarpSystem::Core *getCore();
        private:
            int _length;
            int _width;
            std::string _name;
            short _maxWarp;
            WarpSystem::Core *_core;
            Destination _home;
            Destination _location;
    };
    namespace Starfleet
    {
        class Captain {
            public:
                Captain(std::string);
                ~Captain();

                std::string getName();
                int getAge();
                void setAge(int);
            private:
                std::string _name;
                int _age;
        };
        class Ship {
            public:
                Ship(const int length = 289, const int width = 132, const std::string name = (std::string)"Entreprise", const short maxWarp = 6, int torpedo = 0);
                ~Ship();

                void setupCore(WarpSystem::Core *);
                void checkCore();
                void promote(Captain *);
                bool move(int, Destination);
                bool move(int);
                bool move(Destination d);
                bool move();
                int getShield();
                void setShield(int);
                int getTorpedo();
                void setTorpedo(int torpedo);
                void fire(Borg::Ship *);
                void fire(int, Borg::Ship *);
            private:
                int _length;
                int _width;
                std::string _name;
                short _maxWarp;
                WarpSystem::Core *_core;
                Captain *_captain;
                Destination _home;
                Destination _location;
                int _shield;
                int _photonTorpedo;
        };
        class Ensign {
            public:
                Ensign(std::string);
                ~Ensign();

            private:
                std::string _name;
        };
    } // namespace Starfleet
}
#endif /* !FEDERATION_HPP_ */
