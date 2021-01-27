/*
** EPITECH PROJECT, 2019
** strdup
** File description:
** strdup
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    int lon = my_strlen(src);
    char *str = malloc(sizeof(char) * (lon + 1));

    my_strcpy(str, src);
    return (str);
}
