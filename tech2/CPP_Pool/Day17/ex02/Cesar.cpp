/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD17-jack.goodall
** File description:
** Cesar
*/

#include "Cesar.hpp"

void Cesar::encryptChar(char c)
{
    unsigned char shifted = c;

    if ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A')) {
        shifted = c + _key + 3;
        if (((c <= 'z' && c >= 'a') && shifted > 'z') || ((c <= 'Z' && c >= 'A') && shifted > 'Z'))
            shifted -= 26;
    }
    _key++;
    if (_key == 26) _key = 0;
    std::cout << (char)shifted;
}

void Cesar::decryptChar(char c)
{
    unsigned char shifted = c;

    if ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A')) {
        shifted = c - _key - 3;
        if (((c <= 'z' && c >= 'a') && shifted < 'a') || ((c <= 'Z' && c >= 'A') && shifted < 'A'))
            shifted += 26;
    }
    _key++;
    if (_key == 26) _key = 0;
    std::cout << (char)shifted;
}
