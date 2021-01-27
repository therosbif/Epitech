/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD02A-jack.goodall
** File description:
** information
*/

#include "double_list.h"
#include <stdio.h>

unsigned int double_list_get_size(double_list_t list)
{
    int i = 0;

    for (; list; i++) list = list->next;
    return i;
}

bool double_list_is_empty(double_list_t list)
{
    return ((list == NULL) ? true : false);
}

void double_list_dump(double_list_t list)
{
    if (!list) return;
    do {
        printf("%f\n", list->value);
        list = list->next;
    } while (list);
}
