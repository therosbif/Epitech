/*
** EPITECH PROJECT, 2021
** pushswap
** File description:
** display
*/

#include "pushswap.h"

void print_step(list_t *l_a, list_t *l_b)
{
    my_putstr("\n__________la__________\n");
    for (list_t *tmp = l_a; tmp; tmp = tmp->next) {
        my_put_nbr(tmp->data);
        my_putchar(' ');
    }
    my_putstr("\n__________lb__________\n");
    for (list_t *tmp = l_b; tmp; tmp = tmp->next) {
        my_put_nbr(tmp->data);
        my_putchar(' ');
    }
    my_putstr("\n______________________\n\n");
}

void print_buff(char *str)
{
    if ((buff(GET, 0, 0)[offset(GET) - 3] == 'p' && *str == 'p' &&
            buff(GET, 0, 0)[offset(GET) - 2] != str[1]) ||
        (buff(GET, 0, 0)[offset(GET) - 3] == 's' && *str == 's' &&
            buff(GET, 0, 0)[offset(GET) - 2] == str[1]))
        offset(offset(GET) - 3);
    else {
        if (offset(GET) + 3 >= 1000000) {
            write(1, buff, offset(GET));
            offset(0);
        }
        for (; *str; offset(offset(GET) + 1), str++)
            buff(SET, offset(GET), *str);
    }
}
