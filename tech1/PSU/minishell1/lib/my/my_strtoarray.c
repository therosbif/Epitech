/*
** EPITECH PROJECT, 2019
** project
** File description:
** .
*/

#include "mysh.h"

int cntwords(char *str)
{
    int i = 0;

    if (!*str)
        return 0;
    for (; *str; str++)
        i += (*str != ' ' && (*(str + 1) == ' ' || *(str + 1) == 0));
    return i;
}

int arrlen(char **arr)
{
    int i = 0;

    for (; arr[i]; i++);
    return i;
}

char **arraycat(char **dest, char **src)
{
    int elements = arrlen(dest) + arrlen(src);
    char **final = malloc((elements + 1) * sizeof(char *));
    int i = 0;

    for (; dest[i]; i++) {
        final[i] = my_strdup(dest[i]);
        free(dest[i]);
    }
    free(dest);
    for (int j = 0; src[j]; j++, i++)
        final[i] = src[j];
    final[i] = 0;
    return final;
}

char **my_strtoarray(char *str)
{
    char **array = malloc((cntwords(str) + 1) * sizeof(char *));
    char *ptr = str;
    char q = str[0];
    int inq = 0;
    int i = 0;

    if (!cntwords(str)) {
        free(array);
        return NULL;
    }
    for (; *str; i++, inq = 0, q = str[0]) {
        inq = (*str == '\"' || *str == '\'');
        for (str += inq, ptr = str; *ptr && *ptr != ((inq) ? q : ' '); ptr++);
        (*ptr) ? *ptr++ = 0 : 1;
        array[i] = my_strdup(str);
        for (; *ptr == ' '; ptr++);
        str = ptr;
    }
    array[i] = NULL;
    return array;
}
