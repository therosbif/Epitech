/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush2-jack.goodall
** File description:
** Object
*/

#include "Object.hpp"

Object::Object(const std::string &title, const std::string &type) : _taken(false), _title(title), _type(type)
{
}

Object::~Object()
{
}

std::ostream &operator<<(std::ostream &out, const Object &object)
{
    out << "I am " << object.getTitle() << ", I am a " << object.getType() << " and I am " << ((object.getTaken()) ? "taken." : "not taken.");
    return out;
}
