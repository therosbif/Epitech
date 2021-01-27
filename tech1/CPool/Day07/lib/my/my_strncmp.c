/*
** EPITECH PROJECT, 2019
** strncmp
** File description:
** compare first n chars of s1 to s2
*/

#include <stdio.h>

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int i = 0 ; s1[i] != '\0' && s2[i] != '\0' && i < n ; i++) {
        if (s1[i] > s2[i])
            return (1);
        if (s1[i] < s2[i])
            return (-1);
    }
    return (0);
    
}
