/*
** EPITECH PROJECT, 2019
** concat params
** File description:
** concat params
*/

#include <stdlib.h>
#include "my.h"

char *my_strcat(char *dest, char const *src);

char *concat_params(int ac, char **av)
{
    int len = 0;
    char *str;
    int j = 0;

    for (int i = 0 ; i < ac ; i++)
        len += my_strlen(av[i]);
    str = malloc(1 * (len + ac));
    for ( ; j < ac - 1 ; j++) {
        my_strcat(str, av[j]);
        my_strcat(str, "\n");
    }
    my_strcat(str, av[j]);
    my_strcat(str, "\0");
    return (str);
}
