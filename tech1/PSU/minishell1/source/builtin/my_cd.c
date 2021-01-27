/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_cd
*/

#include "mysh.h"

int my_puterr(char *str)
{
    write(2, str, my_strlen(str));
    return 1;
}

char *getinenv(char const *str, char **env)
{
    int i = 0;
    char *home = NULL;

    for (; my_strncmp(str, env[i], my_strlen(str)); i++);
    if (env[i]) home = my_strdup(env[i] + my_strlen(str) + 1);
    return home;
}

int my_chpwd(char ***env)
{
    char *path = NULL;
    char **args = malloc(4 * sizeof(char *));

    path = getcwd(path, 0);
    args[0] = my_strdup("setenv");
    args[1] = my_strdup("PWD");
    args[2] = my_strdup(path);
    args[3] = 0;
    my_setenv(args, env);
    free(path);
    free_args(args);
    return 0;
}

int my_cd_special(char **arg, char *path, char *old_pwd, char ***env)
{
    int status = 0;
    char *home = getinenv("HOME", *env);

    if (arg[1][0] == '~') {
        arg[1]++;
        arg[1] = my_strcat(home, arg[1]);
        chdir(arg[1]);
    } else if (arg[1][0] == '/')
        status = chdir(arg[1]);
    else status = chdir((old_pwd) ? : path);
    free(home);
    return status;
}

int my_cd(char **arg, char ***env)
{
    char *path = NULL;
    int status = 0;
    char *tmp = NULL;
    char *dest = NULL;

    GET_PATH;
    MY_CD_ARGS_ERROR;
    dest = (arrlen(arg) == 2) ? my_strcat(path, arg[1]) : NULL;
    if (arrlen(arg) == 1)
        status = chdir(getinenv("HOME", *env));
    else if (*arg[1] == '~' || (*arg[1] == '-' && !arg[1][1]) || *arg[1] == '/')
        status = my_cd_special(arg, path, old_pwd, env);
    else status = chdir(dest);
    MY_CD_DIR_ERROR;
    free(old_pwd);
    old_pwd = my_strdup(path);
    my_chpwd(env), free(path), free(dest);
    return status;
}
