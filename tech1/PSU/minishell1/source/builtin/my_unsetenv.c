/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_unsetenv
*/

#include "mysh.h"

void my_remove(char ***env, int i)
{
    char **new = malloc((arrlen(*env)) * sizeof(char *));
    int k = 0;

    for (int j = 0; j < arrlen(*env); j++, j += (j == i), k++)
        if ((*env)[j]) new[k] = my_strdup((*env)[j]);
    new[k] = NULL;
    free_args(*env);
    *env = new;
}

int my_unsetenv(char **arg, char ***env)
{
    int argc = arrlen(arg);
    int i = 0;

    if (argc < 2) {
        write(2, "unsetenv: Too few arguments.\n", 29);
        return 1;
    }
    for (int k = 1; arg[k]; k++) {
        i = 0;
        while ((*env)[i] && my_strncmp(arg[k], (*env)[i], my_strlen(arg[k])))
            i++;
        if ((*env)[i]) my_remove(env, i);
    }
    return 0;
}
