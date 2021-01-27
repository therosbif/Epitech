/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_exit
*/

#include "mysh.h"

int my_exit_error(int argc, char **arg)
{
    int i = 1;

    for (; arg && arg[i]; i++);
    if (i > 2) {
        write(2, "exit: Too many arguments\n", 25);
        return -1;
    } else if (argc == 2 && !my_isint(arg[1])) {
        write(2, "exit: numeric argument required\n", 32);
        return -1;
    }
    return 0;
}

int my_exit(char **arg, __attribute__((unused))char ***env)
{
    int status = (arg && arg[1]) ? my_atoi(arg[1]) : 0;
    int argc = arrlen(arg);

    status = (my_exit_error(argc, arg)) ? : status;
    if (status < 0) return status;
    while (status > 255) status = 256 - status;
    while (status < 0) status = 256 + status;
    return (status);
}
