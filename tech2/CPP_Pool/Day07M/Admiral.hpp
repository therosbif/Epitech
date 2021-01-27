/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD07M-jack.goodall
** File description:
** Admiral
*/

#ifndef ADMIRAL_HPP_
#define ADMIRAL_HPP_

#include "Federation.hpp"
#include "Borg.hpp"

namespace Federation
{
    namespace Starfleet {
        class Admiral {
            public:
                Admiral(std::string);
                ~Admiral();

                bool (Federation::Starfleet::Ship::*movePtr)(Destination d);
                void (Federation::Starfleet::Ship::*firePtr)(Borg::Ship *);
                void fire(Federation::Starfleet::Ship *, Borg::Ship *);
                bool move(Federation::Starfleet::Ship *, Destination);
            private:
                std::string _name;
        };
    }
}

#endif /* !ADMIRAL_HPP_ */
