/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019 [WSL: Ubuntu]
** File description:
** my_strcat
*/

#include <stdlib.h>
#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int j = my_strlen(dest);
    int i = my_strlen(src);
    char *final = malloc(i + j + 1);

    my_strcpy(final, dest);
    my_strcpy(final + j, src);
    return (final);
}
