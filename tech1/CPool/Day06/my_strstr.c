/*
** EPITECH PROJECT, 2019
** strstr
** File description:
** find a substring
*/

#include <stdlib.h>

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;

    for ( ; str[i] != '\0' ; i++) {
        for (int j = 0 ; str[i + j] == to_find[j] && str[i + j + 1] != '\0' ; j++) {
            if (to_find[j + 1] == '\0')
                return (str + i);
        }
    }
    return (NULL);
}
