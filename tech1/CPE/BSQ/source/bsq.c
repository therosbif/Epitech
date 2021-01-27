/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** bsq
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int *my_measure(char *pathname);

int my_min(int a, int b, int c)
{
    a = (b < a) ? b : a;
    a = (c < a) ? c : a;
    return a;
}

int *my_bsq(char *pathname, int *ln)
{
    int fd = open(pathname, O_RDONLY);
    char *b = malloc(ln[0] * (ln[1] + 1) + 21);
    int *bi = malloc(ln[0] * (ln[1] + 1) * 4);
    int *max = malloc(sizeof(int) * 2);
    int len = read(fd, b, ln[0] * (ln[1] + 1) + 20);

    b[len] = 0;
    for (max[0] = 0; b[0] != '\n' ; b++);
    for (int k = 1; k < ln[0]; (b[k * (ln[1] + 1)] != 10)? exit(84) : 1, k++);
    b++;
    max[1] = (b[0] == '.') ? 1 : 0;
    for (int i = 0 ; b[i + 1] ; i++) {
        if ((i < ln[1] + 1 || b[i - (i == 0) ? 0 : 1] == '\n') && b[i] == '.')
            bi[i] = 1;
        else if (b[i] == '.')
            bi[i] = my_min(bi[i - 1], bi[i - ln[1] - 1], bi[i - ln[1] - 2]) + 1;
        else
            bi[i] = 0;
        (bi[max[0]] < bi[i]) ? max[0] = i, max[1] = bi[i] : 1;
    }
    return (max);
}

void display_bsq(char *pathname, int *len, int *sq)
{
    int fd = open(pathname, O_RDONLY);
    char *buff = malloc(len[0] * (len[1] + 1) + 20);
    int ln = read(fd, buff, len[0] * (len[1] + 1) + 20);

    for (; buff[0] != '\n' ; buff++, ln--);
    ln--;
    buff++;
    for (int i = 1 ; i <= sq[1] ; i++) {
        for (int j = 1 ; j <= sq[1] ; j++)
            buff[(sq[0] - (len[1] + 1) * sq[1] - sq[1] + j)
            + (len[1] + 1) * i] = 'x';
    }
    write(1, buff, ln);
}

int main(int ac, char **av)
{
    int fd;
    int *len;
    int *coords;

    if (ac != 2){
        write(2, "ERROR: Invalid arguments", 25);
        exit(84);
    }
    fd = open(av[1], O_RDONLY);
    if (fd < 0){
        write(2, "ERROR: Invalid path", 20);
        exit(84);
    }
    len = my_measure(av[1]);
    coords = my_bsq(av[1], len);
    display_bsq(av[1], len, coords);
    return 0;
}