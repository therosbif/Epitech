/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD02A-jack.goodall
** File description:
** internals
*/

#include "map.h"
#include <stdlib.h>

key_comparator_t key_cmp_container(bool store, key_comparator_t new_key_cmp)
{
    static key_comparator_t key_cmp;

    if (store) key_cmp = new_key_cmp;
    return key_cmp;
}

int pair_comparator(void *first, void *second)
{
    return (*(key_cmp_container(false, NULL)))(first, second);
}

node_t *list_get_first_node_with_key(list_t list, void *value,
    value_comparator_t val_comp)
{
    if (!list) return 0;
    while (list->next && (*val_comp)(value, ((pair_t *)(list->value))->key))
        list = list->next;
    if ((*val_comp)(value, ((pair_t *)(list->value))->key)) return 0;
    return list;
}
