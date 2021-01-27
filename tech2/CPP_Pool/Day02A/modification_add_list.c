/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD02A-jack.goodall
** File description:
** modification_add_list
*/

#include "generic_list.h"
#include <stdlib.h>

bool list_add_elem_at_front(list_t *front_ptr, void *elem)
{
    list_t new = malloc(sizeof(node_t));

    if (!new) return false;
    new->value = elem;
    if (!(*front_ptr)) {
        *front_ptr = new;
        new->next = NULL;
        return true;
    }
    new->next = *front_ptr;
    *front_ptr = new;
    return true;
}

bool list_add_elem_at_back(list_t *front_ptr, void *elem)
{
    list_t new = malloc(sizeof(node_t));
    list_t tmp = *front_ptr;

    if (!new) return false;
    new->value = elem;
    new->next = NULL;
    if (!tmp) {
        *front_ptr = new;
        return true;
    }
    while (tmp->next) tmp = tmp->next;
    tmp->next = new;
    return true;
}

bool list_add_elem_at_position(list_t *front_ptr, void *elem,
    unsigned int position)
{
    list_t new = malloc(sizeof(node_t));
    list_t tmp = *front_ptr;
    unsigned int i = 0;

    if (!new) return false;
    if (!position) {
        free(new);
        return list_add_elem_at_front(front_ptr, elem);
    }
    for (; tmp->next && i < position; i++) tmp = tmp->next;
    if (i != position) return false;
    new->next = tmp->next;
    tmp->next = new;
    new->value = elem;
    return true;
}
