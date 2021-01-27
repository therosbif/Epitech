/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** not_builtin
*/

#include "mysh.h"

int my_isinstr(char c, char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == c) return 1;
    return 0;
}

int getnextpath(char **path, char **executable, char *arg, int i)
{
    char *currpath = NULL;

    for (; (*path)[i] && (*path)[i] != ':'; i++);
    if ((*path)[i])
        i++;
    free(*executable);
    currpath = my_strdup_delim(*path + i, ':');
    *executable = my_strcat(currpath, arg);
    free(currpath);
    return i;
}

int parse_path(char **args, char ***env)
{
    char *path = getinenv("PATH", *env);
    char *currpath = my_strdup_delim(path, ':');
    char *executable = my_strcat(currpath, args[0]);
    int i = 0;
    pid_t p = fork();

    if (!p) {
        if (my_isinstr('/', args[0]) && execve(*args, args, *env) == -1) {
            ERR_CMD, status = 1;
        } else while (execve(executable, args, *env) == -1 && path[i])
            i = getnextpath(&path, &executable, args[0], i);
        (!path[i]) ? execve(*args, args, *env), ERR_CMD, status = 1 : 1;
        exit(1);
    } else status = check_segfault(), wait(&stat_loc);
    free(path), free(currpath), free(executable);
    return (status);
}
