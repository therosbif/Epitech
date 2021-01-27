/*
** EPITECH PROJECT, 2019
** grep
** File description:
** grep
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include "my.h"

void set_zero(char *str, int size)
{
    for (int i = 0 ; i < size ; i++)
        str[i] = 0;
}

void sep_line(char *src, char *ref, int len)
{
    int i = 0;
    int j = 0;
    
    while (j < len) {
        for (i = 0 ; src[i + j] != '\n' && j + i < len - 1 ; i++);
        src[i + j] = '\0';
        if (my_strstr(src + j, ref)) {
            my_putstr(src + j);
            my_putchar('\n');
        }
        j += i + 1;
    }
}

int no_arg(char *buff, char *to_find)
{
    int len = read(0, buff, 3000);

    while (len) {
        if (my_strstr(buff, to_find))
            write(1, buff, len);
        set_zero(buff, len);
        len = read(0, buff, 3000);
    }
    return (0);
}

void add_tobuff(char *buff, int fd, char *to_find)
{
    int len = 1;
    
    while (len) {
        set_zero(buff, 3000);
        len = read(fd, buff, 3000);
        sep_line(buff, to_find, len);
    }
}

int main(int ac, char **av)
{
    int fd = 0;
    char *buff = malloc(3000 + 1);

    if (ac < 2)
        return (84);
    if (ac == 2)
        add_tobuff(buff, 0, av[1]);
    else
        for (int i = 2 ; av[i] ; i++) {
            fd = open(av[i], O_RDONLY);
            if (fd < 0)
                return (84);
            add_tobuff(buff, fd, av[1]);
        }
    return (0);
}
