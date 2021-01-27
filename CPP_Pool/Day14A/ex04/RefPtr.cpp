/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD14A-jack.goodall
** File description:
** RefPtr
*/

#include "RefPtr.hpp"

RefPtr::RefPtr(BaseComponent *rawPtr) : _rawPtr(rawPtr)
{
}

RefPtr::RefPtr(RefPtr const &other)
{
    _rawPtr = new BaseComponent;
    *_rawPtr = *other.get();
}

RefPtr &RefPtr::operator=(RefPtr const &other)
{
    delete _rawPtr;
    _rawPtr = other.get();
    return *this;
}

RefPtr &RefPtr::operator=(BaseComponent *other)
{
    _rawPtr = other;
    return *this;
}
