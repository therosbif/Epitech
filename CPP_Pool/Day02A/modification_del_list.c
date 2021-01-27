/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD02A-jack.goodall
** File description:
** modification_del_list
*/

#include "generic_list.h"
#include <stdlib.h>

bool list_del_elem_at_front(list_t *front_ptr)
{
    list_t tmp = *front_ptr;

    if (!tmp) return false;
    *front_ptr = (*front_ptr)->next;
    free(tmp);
    return true;
}

bool list_del_elem_at_back(list_t *front_ptr)
{
    list_t tmp = *front_ptr;

    if (!tmp) return false;
    if (!(tmp->next)) {
        free(tmp);
        return true;
    }
    while (tmp->next->next) tmp = tmp->next;
    free(tmp->next);
    tmp->next = NULL;
    return true;
}

bool list_del_elem_at_position(list_t *front_ptr, unsigned int position)
{
    list_t tmp = *front_ptr;
    list_t tmp2 = NULL;
    unsigned int i = 0;

    if (!position) return list_del_elem_at_front(front_ptr);
    for (; tmp->next && i < position - 1; i++)
        tmp = tmp->next;
    if (i != position - 1) return false;
    tmp2 = tmp->next;
    tmp->next = tmp2->next;
    free(tmp2);
    return true;
}

void list_clear(list_t *front_ptr)
{
    list_t tmp = *front_ptr;

    while (tmp) {
        tmp = tmp->next;
        free(*front_ptr);
        *front_ptr = tmp;
    }
}
