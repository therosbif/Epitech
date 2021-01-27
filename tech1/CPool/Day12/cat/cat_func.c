/*
** EPITECH PROJECT, 2019
** cat funcs
** File description:
** funcs
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
#include "my.h"

int file_exist(char *buff, int ac, char **av)
{
    int fd = 0;
    int len = 0;

    for (int i = 1 ; i < ac ; i++) {
        fd = open(av[i], O_RDONLY);
        if (fd < 0)
            return (84);
        len = read(fd, buff, 3000);
        while (len) {
            write(1, buff, len);
            len = read(fd, buff, 3000);
        }
    }
    return (0);
}

int no_args(char *buff)
{
    int len = read(0, buff, 3000);

    while (len) {
        write(1, buff, len);
        len = read(0, buff, 3000);
    }
    return (0);
}
