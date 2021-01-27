/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD07M-jack.goodall
** File description:
** BorgQueen
*/

#ifndef BORGQUEEN_HPP_
#define BORGQUEEN_HPP_

#include "Borg.hpp"

namespace Borg
{
    class BorgQueen {
        public:
            BorgQueen();
            ~BorgQueen();

            bool (Borg::Ship::*movePtr)(Destination);
            void (Borg::Ship::*firePtr)(Federation::Starfleet::Ship *);
            void (Borg::Ship::*destroyPtr)(Federation::Ship *);
            bool move(Borg::Ship *, Destination);
            void fire(Borg::Ship *, Federation::Starfleet::Ship *);
            void destroy(Borg::Ship *, Federation::Ship *);
        private:
    };
}

#endif /* !BORGQUEEN_HPP_ */
