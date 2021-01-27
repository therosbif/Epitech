/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_setenv
*/

#include "mysh.h"

int my_setenv_error(int argc, char **arg)
{
    int a = 1;

    if (argc > 3) {
        write(2, "setenv: Too many arguments.\n", 28);
        return 1;
    } else if (argc > 1 && !my_isalpha(arg[1][0])) {
        write(2, "setenv: Variable name must begin with a letter.\n", 48);
        return 1;
    }
    (void)a;
    if (argc > 2 && !my_isalphanum(arg[1])) {
        write(2, SETENV_ERR_ALPHA, 60);
        return 1;
    }
    return 0;
}

void my_insert(char ***arr)
{
    char **tmp = malloc((arrlen(*arr) + 2) * sizeof(char *));
    int j = 0;

    for (; (*arr)[j]; j++) tmp[j] = my_strdup((*arr)[j]);
    tmp[j] = NULL;
    tmp[j + 1] = NULL;
    free_args(*arr);
    *arr = tmp;
}

char **my_arrdup(char **env)
{
    char **dest = malloc((arrlen(env) + 1) * sizeof(char *));
    int i = 0;

    for (; env[i]; i++) dest[i] = my_strdup(env[i]);
    dest[i] = 0;
    return dest;
}

int my_setenv(char **arg, char ***env)
{
    int argc = arrlen(arg);
    int status = my_setenv_error(argc, arg);
    int i = 0;
    char *tmp = NULL;

    if (status) return status;
    if (argc == 1) return my_env(arg, env);
    for (; (*env)[i] && my_strcmp(arg[1], (*env)[i]); i++);
    if (!(*env)[i]) my_insert(env);
    free((*env)[i]);
    (*env)[i] = my_strcat(arg[1], "=");
    tmp = (*env)[i];
    if (argc > 2) {
        (*env)[i] = my_strcat((*env)[i], arg[2]);
        free(tmp);
    }
    return 0;
}
