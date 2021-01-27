/*
** EPITECH PROJECT, 2019
** add in sorted list
** File description:
** add
*/

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "mylist.h"
#include "my.h"

void my_sort_list(linked_list_t **begin, int (*cmp)());
int my_put_in_list(linked_list_t **list, char *data);

void my_add_in_sorted_list(linked_list_t **begin, void *data, int (*cmp)())
{
    my_put_in_list(begin, data);
    my_sort_list(begin, cmp);
}
