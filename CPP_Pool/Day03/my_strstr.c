/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** my_strstr.c
*/

#include "./string.h"

char *my_strstr(const char *haystack, const char *needle)
{
    if (my_strlen(haystack) < my_strlen(needle))
        return NULL;
    if (!my_strncmp(haystack, needle, my_strlen(needle)))
        return((char *)haystack);
    return my_strstr(haystack + 1, needle);
}
