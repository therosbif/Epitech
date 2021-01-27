/*
** EPITECH PROJECT, 2019
** delete nodes
** File description:
** delete nodes
*/

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"

int data_eq(linked_list_t **begin, linked_list_t *prev, linked_list_t *tmp)
{
    if (prev == NULL)
        *begin = tmp->next;
    else
        prev->next = tmp->next;
    return (1);
}

int my_delete_nodes(linked_list_t **begin, void const *data_ref, int (*cmp)())
{
    linked_list_t *tmp = *begin;
    linked_list_t *prev = NULL;
    int i = 0;
    
    while (tmp) {
        if ((*cmp)(tmp->data, data_ref) == 0) {
            i = data_eq(begin, prev, tmp);
            prev = tmp->next;
            tmp = prev->next;
        }
        else {
            prev = tmp;
            tmp = tmp->next;
        }
        if (i == 1) {
            i = 0;
            free(prev);
        }
    }
    return (0);
}
