/*
** EPITECH PROJECT, 2019
** get nbr
** File description:
** convert str to int
*/

#include "my.h"

long long my_getnbr(char const *str)
{
    int negs = 1;
    long long nb = 0;
    int i = 0;

    for ( ; str[i] == '-' || str[i] == '+' ; i++) {
        if (str[i] == '-')
            negs *= -1;
    }
    for (int j = i ; str[j] >= '0' && str[j] <= '9' ; j++)
        nb = (nb * 10 + (str[j] - 48));
    nb *= negs;
    return (nb);
}