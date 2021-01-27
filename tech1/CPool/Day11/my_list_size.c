/*
** EPITECH PROJECT, 2019
** list size
** File description:
** returns list len
*/

#include "mylist.h"

int my_list_size(linked_list_t const *begin)
{
    linked_list_t *tmp = begin;
    int i = 0;

    for ( ; tmp ; i++)
        tmp = (tmp)->next;
    return (i);
}
