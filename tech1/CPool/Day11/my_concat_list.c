/*
** EPITECH PROJECT, 2019
** concat list
** File description:
** concat list
*/

#include <stddef.h>
#include "mylist.h"

void my_concat_list(linked_list_t **begin1, linked_list_t *begin2)
{
    linked_list_t *tmp = *begin1;
    linked_list_t *prev = NULL;

    while (tmp) {
        prev = tmp;
        tmp = (tmp)->next;
    }
    prev->next = begin2;
}
