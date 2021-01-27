/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush2-jack.goodall
** File description:
** Box
*/

#include "Box.hpp"

Box::Box() : Wrap("Box")
{
}

Box::~Box()
{
}

void Box::wrapMeThat(Object *object)
{
    if (_open) {
        if (_object == nullptr) {
            std::cout << "tuuuut tuuut tuut bouate" << std::endl;
            _object = object;
            _open = false;
        } else
            std::cerr << "The Box already contains an object." << std::endl;
    } else
        std::cerr << "The Box is closed." << std::endl;
}
