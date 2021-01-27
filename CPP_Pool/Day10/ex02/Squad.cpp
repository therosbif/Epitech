/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD10-jack.goodall
** File description:
** Squad
*/

#include "Squad.hpp"

Squad::Squad() : _unit(nullptr), _next(nullptr)
{
}

Squad::Squad(ISquad *squad) : _unit(nullptr), _next(nullptr)
{
    Squad *tmp = (Squad *)squad;

    for (int i = 0; tmp; i++, tmp = (Squad *)tmp->_next) {
        push(squad->getUnit(i)->clone());
    }
}

Squad::~Squad()
{
    Squad *tmp = (Squad *)this;
    Squad *next;

    for (; tmp ; tmp = next) {
        next = (Squad *)tmp->_next;
        delete tmp->_unit;
    }
}

int Squad::getCount() const
{
    int count = 0;
    Squad *tmp = (Squad *)this;

    for (; tmp; count++) tmp = (Squad *)tmp->_next;
    return count;
}

ISpaceMarine *Squad::getUnit(int idx)
{
    int i = 0;
    Squad *tmp = this;

    for (; tmp && i != idx ; i++) tmp = (Squad *)tmp->_next;
    if (i != idx) return nullptr;
    return tmp->_unit;
}

int Squad::push(ISpaceMarine *elem)
{
    Squad *tmp = this;

    if (elem == nullptr) return getCount();
    if (tmp->_unit == nullptr) {
        tmp->_unit = elem;
        return getCount();
    }
    for (; tmp->_next ; tmp = (Squad *)tmp->_next)
        if (elem == tmp->_unit) return getCount();
    tmp->_next = new Squad();
    ((Squad *)(tmp->_next))->setUnit(elem);
    return getCount();
}

Squad &Squad::operator=(Squad &squad)
{
    Squad *tmp = this;
    Squad *next;

    for (; tmp ; tmp = next) {
        next = (Squad *)tmp->_next;
        delete tmp;
    }
    tmp = &squad;
    for (int i = 0; tmp; i++, tmp = (Squad *)tmp->_next) {
        push(squad.getUnit(i)->clone());
    }
    return *this;
}
