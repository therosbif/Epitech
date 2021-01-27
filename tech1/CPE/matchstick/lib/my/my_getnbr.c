/*
** EPITECH PROJECT, 2019
** get nbr
** File description:
** convert str to int
*/

#include "my.h"

int my_getnbr(char const *str)
{
    int negs = 0;
    long nb = 0;
    int i = 0;
    int j = 0;

    for ( ; str[i] == '-' || str[i] == '+' ; i++) {
        if (str[i] == '-')
            negs++;
    }
    for (j = i ; str[j] >= '0' && str[j] <= '9' ; j++)
        nb = (nb * 10 + (str[j] - 48));
    if (negs % 2 == 1)
        nb *= -1;
    if (nb >= 2147483647 || nb <= -2147483648)
        return (0);
    return (nb);
}
