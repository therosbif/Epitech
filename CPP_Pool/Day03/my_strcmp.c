/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** compare two strings
*/

#include <stdlib.h>

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

int my_strncmp(char const *s1, char const *s2, size_t n)
{
    for (size_t i = 0 ; (s1[i] || s2[i]) && i < n; i++) {
        if (s1[i] > s2[i])
            return (1);
        if (s1[i] < s2[i])
            return (-1);
    }
    return (0);
}
