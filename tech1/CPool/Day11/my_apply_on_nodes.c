/*
** EPITECH PROJECT, 2019
** apply on nodes
** File description:
** apply function to nodes
*/

#include "mylist.h"

int my_apply_on_nodes(linked_list_t *begin, int (*f)(void *))
{
    while (begin) {
        (*f)(begin->data);
        begin = begin->next;
    }
    return (0);
}
