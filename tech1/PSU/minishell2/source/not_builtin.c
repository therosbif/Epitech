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

void err_cmd(char *cmd)
{
    struct stat st;

    my_puterr(cmd);
    if (errno == 8) my_puterr(": Exec format error. Wrong Architecture.\n");
    else my_puterr((lstat(cmd, &st) == -1) ?
        ": Command not found.\n" : ": Permission denied.\n");
    exit(1);
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
            err_cmd(args[0]), status = 1;
        } else while (execve(executable, args, *env) == -1 && path[i])
            i = getnextpath(&path, &executable, args[0], i);
        if (!path[i]) execve(*args, args, *env), err_cmd(args[0]);
        exit(0);
    } else {
        waitpid(p, &i, 0);
        if (WIFEXITED(i)) status = WEXITSTATUS(i);
        else status = check_segfault();
    }
    free(path), free(currpath), free(executable);
    return (status);
}
