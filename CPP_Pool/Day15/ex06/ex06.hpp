/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD15-jack.goodall
** File description:
** ex06
*/

#ifndef EX06_HPP_
#define EX06_HPP_

#include <iostream>
#include <typeinfo>
#include <string.h>
#include <sstream>

template<typename T>
static std::string get_str(const T &a)
{
    std::ostringstream str;

    if (std::string(typeid(a).name()) == typeid(int).name())
        str << "[int:" << a << "]";
    else if (std::string(typeid(a).name()) == typeid(float).name())
        str << "[float:" << a << "f]";
    else if (std::string(typeid(a).name()) == typeid(std::string).name())
        str << "[string:\"" << a << "\"]";
    else
        str << "[???]";
    return str.str();
}

template<typename T, typename U = T>
struct Tuple {
    T a;
    U b;

    std::string toString() const
    {
        std::ostringstream str;
        str << "[TUPLE ";

        str << get_str(a);
        str << " ";
        str << get_str(b);
        str << "]";
        return str.str();
    }
};

#endif /* !EX06_HPP_ */
