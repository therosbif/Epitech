/*
** EPITECH PROJECT, 2019
** sort
** File description:
** list
*/

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "mylist.h"
#include "my.h"

int cmp_true
(linked_list_t *prev, linked_list_t *curr,
linked_list_t *aft, linked_list_t **begin)
{
    curr->next = aft->next;
    aft->next = curr;
    if (prev != NULL)
        prev->next = aft;
    else
        *begin = aft;
    return (1);
}

void my_sort_list(linked_list_t **begin, int (*cmp)())
{
    linked_list_t *prev = NULL;
    linked_list_t *curr = *begin;
    linked_list_t *aft = (*begin)->next;
    int sort = 1;

    while(sort) {
        sort = 0;
        while (aft) {
            if ((*cmp)(curr->data, aft->data) > 0)
                sort = cmp_true(prev, curr, aft, begin);
            prev = curr;
            curr = curr->next;
            aft = curr->next;
        }
    }
}
