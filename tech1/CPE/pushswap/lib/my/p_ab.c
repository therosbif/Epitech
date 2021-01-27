/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** p_ab
*/

#include "pushswap.h"

void pa(list_t **l_a, list_t **l_b, char *str)
{
    list_t *tmp = *l_b;

    if (*l_b) {
        PRINT_BUFF;
        *l_b = (*l_b)->next;
        tmp->next = *l_a;
        *l_a = tmp;
        PRINT_STEP;
    }
}

void pb(list_t **l_a, list_t **l_b)
{
    pa(l_b, l_a, "pb ");
}
