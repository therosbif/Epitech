/*
** EPITECH PROJECT, 2019
** put str
** File description:
** print a str
*/

#include "pushswap.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        my_putchar(str[i]);
        i++;
    }
    return (0);
}

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
