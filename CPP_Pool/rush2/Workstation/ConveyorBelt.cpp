/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** ConveyorBelt
*/

#include "ConveyorBelt.hpp"
#include <iostream>
#include "../Wrap/Box.hpp"
#include "../Wrap/GiftPaper.hpp"

PapaXmasConveyorBelt::PapaXmasConveyorBelt()
: _object(nullptr), _input(1), _output(1)
{
    std::cout << "New belt created" << std::endl;
}

PapaXmasConveyorBelt::~PapaXmasConveyorBelt()
{
    std::cout << "Belt's end reached" << std::endl;
}

void PapaXmasConveyorBelt::in(const std::string &type)
{
    if (!_output || !_input) {
        std::cerr << "output/inptut isn't set" << std::endl;
        return ;
    }
    if (_object) {
        std::cerr << "belt full" << std::endl;
        return ;
    }
    if (type == "Box")
        _object = new(Box);
    else
        _object = new(GiftPaper);
}

void PapaXmasConveyorBelt::out()
{
    if (!_output || !_input) {
        std::cerr << "output/inptut isn't set" << std::endl;
        return ;
    }
    if (!_object) {
        std::cerr << "belt empty" << std::endl;
        return ;
    }
    _object = nullptr;
}

Object *PapaXmasConveyorBelt::take()
{
    Object *tmp;
    if (_object != nullptr) {
        tmp = _object;
        tmp->isTaken();
        _object = nullptr;
        return tmp;
    } else
        std::cerr << "The Coveyor Belt is empty." << std::endl;
    return nullptr;
}

bool PapaXmasConveyorBelt::put(Object *object)
{
    if (_object == nullptr) {
        _object = object;
        return true;
    } else
        std::cerr << "The Conveyor Belt is full." << std::endl;
    return false;
}

IConveyorBelt *createConveyorBelt()
{
    return new PapaXmasConveyorBelt;
}

ConveyorBeltRand::ConveyorBeltRand()
{
}

ConveyorBeltRand::~ConveyorBeltRand()
{}

void ConveyorBeltRand::in(const std::string &type)
{
    (void)type;
    if (!_output || !_input) {
        std::cerr << "output/inptut isn't set" << std::endl;
        return ;
    }
    if (random() % 2)
        _object = new(Box);
    else
        _object = new(GiftPaper);
}

void ConveyorBeltRand::out()
{
    if (!_output || !_input) {
        std::cerr << "output/inptut isn't set" << std::endl;
        return ;
    }
    if (!_object) {
        std::cerr << "belt empty" << std::endl;
        return ;
    }
    std::cout << this->_object->xml();
    _object = nullptr;

}