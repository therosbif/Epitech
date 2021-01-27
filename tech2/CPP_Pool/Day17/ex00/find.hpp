/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD17-jack.goodall
** File description:
** find
*/

#ifndef FIND_HPP_
#define FIND_HPP_

#include <algorithm>

template<class T>
class T::iterator do_find(T &t, int i)
{
    return std::find(t.begin(), t.end(), i);
}

#endif /* !FIND_HPP_ */
