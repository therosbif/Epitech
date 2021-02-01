/*
** EPITECH PROJECT, 2021
** pushswap
** File description:
** global
*/

#include "pushswap.h"

int offset(int i)
{
    static int off;

    if (i != GET)
        off = i;
    return off;
}

int flag(int i)
{
    static int _flag;

    if (i != GET)
        _flag = i;
    return _flag;
}

char *buff(char action, int idx, char c)
{
    static char buff_[1000000];

    if (action == SET)
        buff_[idx] = c;
    return buff_;
}
