/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_env
*/

#include "mysh.h"

int my_env_error(char **arg)
{
    int argc = arrlen(arg);

    if (argc > 1) {
        write(2, "env: Takes no arguments\n", 24);
        return -1;
    }
    return 0;
}

int my_env(char **arg, char ***env)
{
    int status = 0;

    status = my_env_error(arg);
    if (status < 0) return status;
    for (int i = 0; i < arrlen(*env); my_putchar('\n'), i++)
        my_putstr((*env)[i]);
    return 0;
}
