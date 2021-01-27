/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD02A-jack.goodall
** File description:
** value
*/

#include "double_list.h"
#include <stdlib.h>

double double_list_get_elem_at_front(double_list_t list)
{
    if (list)
        return list->value;
    return 0;
}

double double_list_get_elem_at_back(double_list_t list)
{
    if (list) {
        while (list->next) list = list->next;
        return list->value;
    }
    return 0;
}

double double_list_get_elem_at_position(double_list_t list,
    unsigned int position)
{
    unsigned int i = 0;

    if (!list) return 0;
    for (; list->next && i < position; i++) list = list->next;
    if (i != position) return 0;
    return list->value;
}

doublelist_node_t *double_list_get_first_node_with_value(double_list_t list,
    double value)
{
    if (!list) return NULL;
    while (list->next && value != list->value) list = list->next;
    if (value != list->value) return NULL;
    return list;
}
