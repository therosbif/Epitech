/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD02A-jack.goodall
** File description:
** value_list
*/

#include "generic_list.h"

void *list_get_elem_at_front(list_t list)
{
    if (list)
        return list->value;
    return 0;
}

void *list_get_elem_at_back(list_t list)
{
    if (list) {
        while (list->next) list = list->next;
        return list->value;
    }
    return 0;
}

void *list_get_elem_at_position(list_t list, unsigned int position)
{
    unsigned int i = 0;

    if (!list) return 0;
    for (; list->next && i < position; i++) list = list->next;
    if (i != position) return 0;
    return list->value;
}

node_t *list_get_first_node_with_value(list_t list, void *value,
    value_comparator_t val_comp)
{
    if (!list) return 0;
    while (list->next && (*val_comp)(value, list->value))
        list = list->next;
    if ((*val_comp)(value, list->value)) return 0;
    return list;
}
