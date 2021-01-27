/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD15-jack.goodall
** File description:
** ex03
*/

#ifndef EX03_HPP_
#define EX03_HPP_

#include <iostream>

template<typename T>
void foreach(T *arr, void (&func)(const T &elem), int size)
{
    for (int i = 0; i < size; i++) {
        func(arr[i]);
    }
}

template<typename T>
void print(const T &elem)
{
    std::cout << elem << std::endl;
}

#endif /* !EX03_HPP_ */
