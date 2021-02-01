/*
** EPITECH PROJECT, 2021
** Day03
** File description:
** my_print_combn
*/

#include <unistd.h>

int nbrlen(int n)
{
    int i = 1;

    while (n >= 10) {
        n /= 10;
        i++;
    }
    return i;
}

int my_print_combn(int n)
{
    for (int i = 0; nbrlen(i) <= n;) {
        for (int j = 0; j < n - nbrlen(i); j++)
            my_putchar('0');
        my_put_nbr(i);
        i++;
        if (nbrlen(i) <= n) {
            my_putchar(',');
            my_putchar(' ');
        }
    }
    return 0;
}
