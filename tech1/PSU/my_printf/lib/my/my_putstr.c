/*
** EPITECH PROJECT, 2019
** put str
** File description:
** print a str
*/

#include <stdlib.h>
#include "my.h"

char *convert(char *base, unsigned long num);

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        my_putchar(str[i]);
        i++;
    }
    return (0);
}

char *my_append(char *dest, char src)
{
    int len = my_strlen(dest);
    char *final = malloc(len + 1);

    final = my_strdup(dest);
    final[len] = src;
    final[len + 1] = 0;
    return final;
}

char *my_nprint(char const *str)
{
    char *dest = "\0";

    for (int i = 0 ; str[i] != '\0' ; i++){
        if (str[i] < 32 || str[i] > 126){
            dest = my_append(dest, '\\');
            dest = my_strcat(dest, convert("01234567", str[i]));
        }
        else
            dest = my_append(dest, str[i]);
    }
    return (dest);
}