/*
** EPITECH PROJECT, 2019
** project
** File description:
** .
*/

#include <count_words.h>

int my_strlen(char *str)
{
    return (*str) ? my_strlen(str + 1) + 1 : 0;
}

int my_strcmp(char const *s1, char const *s2)
{
    for (int i = 0 ; s1[i] != '\0' || s2[i] != '\0' ; i++) {
        if (s1[i] > s2[i])
            return (1);
        if (s1[i] < s2[i])
            return (-1);
    }
    return (0);
}

char *my_strdup(char *str)
{
    char *dest = malloc(my_strlen(str) + 1);
    int i = 0;

    for (; *str; i++, str++)
        dest[i] = *str;
    dest[i] = 0;
    return dest;
}
