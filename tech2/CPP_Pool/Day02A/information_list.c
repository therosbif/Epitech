/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD02A-jack.goodall
** File description:
** information_list
*/

#include "generic_list.h"
#include <stdlib.h>

unsigned int list_get_size(list_t list)
{
    int i = 0;

    for (; list; i++) list = list->next;
    return i;
}

bool list_is_empty(list_t list)
{
    return ((list == NULL) ? true : false);
}

void list_dump(list_t list, value_displayer_t val_disp)
{
    if (!list) return;
    do {
        (*val_disp)(list->value);
        list = list->next;
    } while (list);
}
