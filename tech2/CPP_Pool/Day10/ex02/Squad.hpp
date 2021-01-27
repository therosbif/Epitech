/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD10-jack.goodall
** File description:
** Squad
*/

#ifndef SQUAD_HPP_
#define SQUAD_HPP_

#include "ISquad.hpp"
#include "ISpaceMarine.hpp"

class Squad : public ISquad {
    public:
        Squad();
        Squad(ISquad *squad);
        ~Squad();

        int getCount() const;
        ISpaceMarine* getUnit(int);
        int push(ISpaceMarine *);
        Squad &operator=(Squad &squad);
        void setUnit(ISpaceMarine *unit) { _unit = unit; };

    private:
        ISpaceMarine *_unit;
        ISquad *_next;
};

#endif /* !SQUAD_HPP_ */
