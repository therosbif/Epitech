/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD02A-jack.goodall
** File description:
** modification_del
*/

#include "double_list.h"
#include <stdlib.h>

bool double_list_del_elem_at_front(double_list_t *front_ptr)
{
    double_list_t tmp = *front_ptr;

    if (!tmp) return false;
    *front_ptr = (*front_ptr)->next;
    free(tmp);
    return true;
}

bool double_list_del_elem_at_back(double_list_t *front_ptr)
{
    double_list_t tmp = *front_ptr;

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

bool double_list_del_elem_at_position(double_list_t *front_ptr,
    unsigned int position)
{
    double_list_t tmp = *front_ptr;
    double_list_t tmp2 = NULL;
    unsigned int i = 0;

    if (!position) return double_list_del_elem_at_front(front_ptr);
    for (; tmp->next && i < position - 1; i++)
        tmp = tmp->next;
    if (i != position - 1) return false;
    tmp2 = tmp->next;
    tmp->next = tmp2->next;
    free(tmp2);
    return true;
}
