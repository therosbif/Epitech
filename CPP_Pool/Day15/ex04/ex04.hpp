/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD15-jack.goodall
** File description:
** ex04
*/

#ifndef EX04_HPP_
#define EX04_HPP_

#include <string>

template<typename T>
bool equal(const T &a, const T &b);


template<typename T>
class Tester {
    public:
        bool equal(const T &a, const T &b) const;
};

#endif /* !EX04_HPP_ */
