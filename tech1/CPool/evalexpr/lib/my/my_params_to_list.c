/*
** EPITECH PROJECT, 2019
** params to list
** File description:
** puts params in list
*/

#include <stdlib.h>
#include "my.h"

int my_put_in_list(linked_list_t **list, void *data, int type)
{
    linked_list_t *element = malloc(sizeof(*element));

    element->data = data;
    element->type = type;
    element->next = *list;
    *list = element;
    return (0);
}