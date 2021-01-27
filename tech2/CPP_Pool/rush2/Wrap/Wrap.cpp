/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush2-jack.goodall
** File description:
** Wrap
*/

#include "Wrap.hpp"

Wrap::Wrap(const std::string &type) : Object("Wrap", type)
{
}

Wrap::~Wrap()
{

}

Wrap *Wrap::isTaken() {
    if (!_taken) {
        std::cout << "whistles while working" << std::endl;
        _taken = true;
    } else
        std::cerr << "Wrap is already being held." << std::endl;
    return this;
}

Object *Wrap::takeObject()
{
    Object *tmp;

    if (_open) {
        if (_object != nullptr) {
            _object->isTaken();
            tmp = _object;
            _object = nullptr;
            return tmp;
        } else
            std::cerr << "No Object in Wrap" << std::endl;
        return nullptr;
    } else
        std::cerr << "Wrap is closed" << std::endl;
    return nullptr;
}

std::string Wrap::xml()
{
    return "<" + this->getType() + ">\n"
    + this->_object->xml() + "</" + this->getType() + ">\n";
}