/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019 [WSL: Ubuntu]
** File description:
** my_strcat
*/

#include "my_ls.h"

int my_strlen(char const *str)
{
    int i = 0;

    for ( ; str[i] != '\0' ; i++) {}
    return (i);
}

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for ( ; src[i] != '\0' ; i++)
        dest[i] = src[i];
    dest[i] = 0;
    return (dest);
}

char *my_strcat(char *dest, char const *src, int slash)
{
    int j = my_strlen(dest);
    int i = my_strlen(src);
    char *final = malloc(i + j + 2);

    my_strcpy(final, dest);
    if (slash) {
        (dest[j - 1] != '/') ? final[j++] = '/' : 1;
        final[j] = 0;
    }
    my_strcpy(final + j, src);
    final[i + j] = (slash) ? '0' : ' ';
    final[i + j + 1 - slash] = 0;
    return (final);
}

char *my_strdup(char const *src)
{
    char *str = malloc(sizeof(char) * (my_strlen(src) + 1));

    my_strcpy(str, src);
    return (str);
}

int my_strcmp(char const *s1, char const *s2)
{
    int off1 = (*s1 == '.');
    int off2 = (*s2 == '.');

    for (int i = 0 ; s1[i + off1] != '\0' || s2[i + off2] != '\0' ; i++) {
        if (s1[i+ off1] > s2[i + off2])
            return (1);
        if (s1[i + off1] < s2[i + off2])
            return (-1);
    }
    return (0);
}
