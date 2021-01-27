/*
** EPITECH PROJECT, 2019
** my put nbr
** File description:
** puts number
*/

#include "pushswap.h"

int my_putchar(char c)
{
    write(1, &c, 1);
    return 0;
}

int my_put_nbr(int nb)
{
    long div = 1;
    long num = nb;
    int n = 0;

    while (num % div != num) {
        n++;
        div = div * 10;
    }
    if (num < 0) {
        my_putchar('-');
        div = -div;
    }
    if (n == 0)
        my_putchar(48);
    for (int i = 0 ; i < n ; i++) {
        my_putchar(48 + ((num % div)/(div/10)));
        div = div / 10;
    }
    return (0);
}

void free_list(list_t *l_a)
{
    list_t *tmp = NULL;

    while (l_a && l_a->next) {
        tmp = l_a;
        l_a = l_a->next;
        free(tmp);
    }
    free(l_a);
}
