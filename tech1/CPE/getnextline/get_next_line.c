/*
** EPITECH PROJECT, 2019
** CPE_getnextline_2019
** File description:
** main
*/

#include "get_next_line.h"

int my_strlen(char const *str)
{
    return ((*str) ? my_strlen(++str) + 1 : 0);
}

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for ( ; src[i] != '\0' ; i++)
        dest[i] = src[i];
    dest[i] = 0;
    return (dest);
}

void init_file(char **file, char *buff, int fd)
{
    int len = 0;

    *file = malloc(1);
    **file = 0;
    do {
        STRCAT;
        len = read(fd, buff, READ_SIZE);
        buff[len] = 0;
    } while (len);
}

int init_len(char **buff, int fd)
{
    if (fd < 0)
        return (-1);
    if (*buff){
        *buff[0] = 0;
        return (read(fd, *buff, READ_SIZE));
    }
    return -1;
}

char *get_next_line(int fd)
{
    static char *file;
    char *buff = malloc(READ_SIZE + 1);
    int len = init_len(&buff, fd);

    if (len < 0)
        return NULL;
    if (len) {
        buff[len] = 0;
        init_file(&file, buff, fd);
    }
    if (!*file)
        return NULL;
    buff = file;
    for (; *file != '\n' && *file; file++);
    if (*file)
        *file++ = 0;
    return buff;
}

