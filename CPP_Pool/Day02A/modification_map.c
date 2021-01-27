/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD02A-jack.goodall
** File description:
** map
*/

#include "map.h"
#include <stdlib.h>

node_t *list_get_first_node_with_key(list_t list, void *value,
    value_comparator_t val_comp);

void *make_pair(void *key, void *value)
{
    pair_t *pair = malloc(sizeof(pair_t));

    pair->key = key;
    pair->value = value;
    return pair;
}

bool map_add_elem(map_t *map_ptr, void *key, void *value,
    key_comparator_t key_cmp)
{
    map_t addr;

    key_cmp_container(true, key_cmp);
    addr = list_get_first_node_with_key(*map_ptr,
        key, (key_cmp));
    if (addr)
        ((pair_t *)(addr->value))->value = value;
    else
        return list_add_elem_at_front(map_ptr, make_pair(key, value));
    return true;
}

bool map_del_elem(map_t *map_ptr, void *key, key_comparator_t key_cmp)
{
    map_t addr;

    key_cmp_container(true, key_cmp);
    addr = list_get_first_node_with_key(*map_ptr,
        key, (key_cmp));
    if (addr)
        return list_del_node(map_ptr, addr);
    return false;
}

void *map_get_elem(map_t map, void *key, key_comparator_t key_cmp)
{
    map_t addr;

    key_cmp_container(true, key_cmp);
    addr = list_get_first_node_with_key(map,
        key, (key_cmp));
    if (addr)
        return ((pair_t *)(addr->value))->value;
    return NULL;
}
