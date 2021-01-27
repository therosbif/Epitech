/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD02A-jack.goodall
** File description:
** modification
*/

#include "double_list.h"
#include <stdlib.h>

bool double_list_add_elem_at_front(double_list_t *front_ptr, double elem)
{
    double_list_t new = malloc(sizeof(doublelist_node_t));

    if (!new) return false;
    new->value = elem;
    if (!*front_ptr) {
        *front_ptr = new;
        new->next = NULL;
        return true;
    }
    new->next = *front_ptr;
    *front_ptr = new;
    return true;
}

bool double_list_add_elem_at_back(double_list_t *front_ptr, double elem)
{
    double_list_t new = malloc(sizeof(doublelist_node_t));
    double_list_t tmp = *front_ptr;

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

bool double_list_add_elem_at_position(double_list_t *front_ptr, double elem,
    unsigned int position)
{
    double_list_t new = malloc(sizeof(doublelist_node_t));
    double_list_t tmp = *front_ptr;
    unsigned int i = 0;

    if (!new) return false;
    if (!position) {
        free(new);
        return double_list_add_elem_at_front(front_ptr, elem);
    }
    for (; tmp->next && i < position; i++) tmp = tmp->next;
    if (i != position) return false;
    new->next = tmp->next;
    tmp->next = new;
    new->value = elem;
    return true;
}
