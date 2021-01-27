/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD15-jack.goodall
** File description:
** ex02
*/

#ifndef EX02_HPP_
#define EX02_HPP_

#include <iostream>

template<typename T>
T min(T a, T b)
{
    std::cout << "template min" << std::endl;
    return ((a <= b) ? a : b);
}

int min(int a, int b)
{
    std::cout << "non-template min" << std::endl;
    return ((a <= b) ? a : b);
}

template<typename T>
T templateMin(T *arr, int size)
{
    T tmp = arr[0];

    for (int i = 1; i < size; i++) {
        tmp = min<T>(tmp, arr[i]);
    }
    return tmp;
}

int nonTemplateMin(int *arr, int size)
{
    int tmp = arr[0];

    for (int i = 1; i < size; i++) {
        tmp = min(tmp, arr[i]);
    }
    return tmp;
}



#endif /* !EX02_HPP_ */
