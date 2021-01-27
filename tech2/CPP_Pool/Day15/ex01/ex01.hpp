/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD15-jack.goodall
** File description:
** ex01
*/

#ifndef EX01_HPP_
#define EX01_HPP_

#include <cstring>

template<typename T>
int compare(const T &a, const T &b)
{
    if (a == b)
        return 0;
    if (a < b)
        return -1;
    return 1;
}

template<>
int compare<const char*>(const char * const &a, const char * const &b)
{
    int i = strcmp(a, b);

    if (i == 0) return 0;
    if (i < 0) return -1;
    return 1;
}

#endif /* !EX01_HPP_ */
