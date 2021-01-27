/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** s_abc
*/

#include "pushswap.h"

void sa(list_t **l_a, list_t **l_b, char *str)
{
    list_t *tmp = (*l_a)->next;

    if ((*l_a)->next){
        PRINT_BUFF;
        (*l_a)->next = tmp->next;
        tmp->next = *l_a;
        *l_a = tmp;
        PRINT_STEP;
    }
}

void sb(list_t **l_a, list_t **l_b)
{
    sa(l_b, l_a, "sb ");
}

void sc(list_t **l_a, list_t **l_b)
{
    sa(l_a, l_b, "sc ");
    sa(l_b, l_a, "");
}
