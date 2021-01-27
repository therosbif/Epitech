/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** measure
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int my_lines(char *pathname)
{
    int fd = open(pathname, O_RDONLY);
    char buff[20];
    int len;

    len = read(fd, buff, 20);
    buff[len] = 0;
    return (my_getnbr(buff));
}

int my_len(char *pathname)
{
    int fd = open(pathname, O_RDONLY);
    char buff[1];
    int i = 0;

    buff[0] = 0;
    for (; buff[0] != '\n' ; read(fd, buff, 1));
    read(fd, buff, 1);
    for (; buff[0] != '\n' ; read(fd, buff, 1), i++);
    return (i);
}

int *my_measure(char *pathname)
{
    int *len = malloc(8);

    len[0] = my_lines(pathname);
    if (len[0] == 0){
        write(2, "ERROR: Not enough lines", 24);
        exit(84);
    }
    len[1] = my_len(pathname);
    return (len);
}