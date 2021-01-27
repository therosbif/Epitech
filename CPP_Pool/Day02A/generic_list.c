/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD02A-jack.goodall
** File description:
** generic_list
*/

#include "generic_list.h"

bool list_del_node(list_t *front_ptr, node_t *node_ptr)
{
    list_t tmp = *front_ptr;
    unsigned int i = 0;

    for (;tmp && node_ptr != tmp; i++) tmp = tmp->next;
    if (node_ptr != tmp) return false;
    return list_del_elem_at_position(front_ptr, i);
}
