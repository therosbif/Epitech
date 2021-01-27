/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD17-jack.goodall
** File description:
** OneTime
*/

#include "OneTime.hpp"

OneTime::OneTime(const std::string &key) : _key(key), _idx(0)
{
}

static char placeInAlpha(char c)
{
    if (c <= 'z' && c >= 'a')
        return c - 'a';
    if (c <= 'Z' && c >= 'A')
        return c - 'A';
    return 0;
}

void OneTime::encryptChar(char c)
{
    unsigned char shifted = c;

    if ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A')) {
        shifted = c + placeInAlpha(_key[_idx]);
        if (((c <= 'z' && c >= 'a') && shifted > 'z') || ((c <= 'Z' && c >= 'A') && shifted > 'Z'))
            shifted -= 26;
    }
    _idx++;
    if (!_key[_idx]) _idx = 0;
    std::cout << (char)shifted;
}

void OneTime::decryptChar(char c)
{
    unsigned char shifted = c;

    if ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A')) {
        shifted = c - placeInAlpha(_key[_idx]);
        if (((c <= 'z' && c >= 'a') && shifted < 'a') || ((c <= 'Z' && c >= 'A') && shifted < 'A'))
            shifted += 26;
    }
    _idx++;
    if (!_key[_idx]) _idx = 0;
    std::cout << (char)shifted;
}
