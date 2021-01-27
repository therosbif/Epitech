/*
** EPITECH PROJECT, 2019
** find node
** File description:
** return adress of matching data
*/

#include <stddef.h>
#include "mylist.h"

linked_list_t *my_find_node
(linked_list_t const *begin, void const *data_ref, int (*cmp)())
{
    linked_list_t *tmp = begin;
    int i = 0;

    for ( ; tmp ; i++) {
        if ((*cmp)(tmp->data, data_ref) == 0)
            return (tmp);
        tmp = (tmp)->next;
    }
    return (NULL);
}
