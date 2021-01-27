/*
** EPITECH PROJECT, 2019
** evalexpr
** File description:
** bootstrap
*/

#include <stdio.h>
#include "my.h"
#include "opps.h"

int my_is_opp(char c)
{
    if (c == '-' || c == '+' || c == '*' || c == '/' || c == '%' || c == '(')
        return 1;
    return 0;
}

int my_is_num(char c)
{
    return (c >= '0' && c <= '9') ? 1 : 0;
}

void *my_getnbr2(char const *str)
{
    long nb = 0;

    for (int j = 0 ; str[j] >= '0' && str[j] <= '9'; j++)
        nb = (nb * 10 + (str[j] - 48));
    if (nb >= 2147483647 || nb <= -2147483648)
        return (0);
    return ((void *)nb);
}