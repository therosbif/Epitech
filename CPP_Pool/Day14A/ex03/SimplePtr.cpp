/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD14A-jack.goodall
** File description:
** SimplePtr
*/

#include "SimplePtr.hpp"

SimplePtr::SimplePtr(BaseComponent *rawPtr) : _rawPtr(rawPtr)
{
}

SimplePtr::~SimplePtr()
{
    delete _rawPtr;
}
