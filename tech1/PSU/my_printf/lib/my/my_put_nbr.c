/*
** EPITECH PROJECT, 2019
** my put nbr
** File description:
** puts number
*/

#include "my.h"

int my_put_nbr(long long nb)
{
    long long div = 1;
    int n = 0;

    for (; nb % div != nb ; n++, div *= 10);
    if (nb < 0) {
        my_putchar('-');
        div *= -1;
    }
    if (n == 0)
        my_putchar(48);
    for (int i = 0 ; i < n ; i++, div /= 10)
        my_putchar(48 + ((nb % div)/(div/10)));
    return (0);
}

int my_put_uint(unsigned long long nb)
{
    long long div = 1;
    int n = 0;

    for (; nb % div != nb ; n++, div *= 10);
    if (n == 0)
        my_putchar(48);
    for (int i = 0 ; i < n ; i++, div /= 10)
        my_putchar(48 + ((nb % div)/(div/10)));
    return (0);
}
