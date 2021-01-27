/*
** EPITECH PROJECT, 2019
** bonus
** File description:
** base_convert.c
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int get_n(int base, int nb);
int get_n_u(int nb, int base);

char *base_conv(long long nb, int base, char upper)
{
    int len = get_n(nb, base);
    char *res = malloc(len + 1);
    long long digit = 0;
    int offset = (upper == 'x') ? 97 : 65;

    for (int i = 1; nb >= base; i++) {
            digit = nb % base;
        nb = nb / base;
        if (digit > 9)
            res[len - i] = digit - 10 + offset;
        else
            res[len - i] = digit + 48;
    }
    res[0] = (nb > 10) ? nb - 10 + offset : nb + 48;
    res[len] = 0;
    return res;
}

int get_n(int nb, int base)
{
    int save = base;
    int n = 1;

    while (base * save <= nb) {
        base *= save;
        n++;
    }
    return n + 1;
}
