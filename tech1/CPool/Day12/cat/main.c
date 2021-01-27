/*
** EPITECH PROJECT, 2019
** cat
** File description:
** cat
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
#include "my.h"

int file_exist(char *buff, int ac, char **av);
int no_args(char *buff);

int main(int ac, char **av)
{
    char buff[3000];

    if (ac > 1)
        return (file_exist(buff, ac, av));
    if (ac == 1)
        return (no_args(buff));
}
