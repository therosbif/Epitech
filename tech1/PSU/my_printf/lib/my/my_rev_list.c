/*
** EPITECH PROJECT, 2019
** rev list
** File description:
** rev list order
*/

#include <stdlib.h>
#include "my.h"

void my_rev_list(linked_list_t **begin)
{
    linked_list_t *prev = NULL;
    linked_list_t *curr = *begin;
    linked_list_t *next = NULL;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *begin = prev;
}
