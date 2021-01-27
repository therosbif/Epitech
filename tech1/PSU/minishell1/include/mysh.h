/*
** EPITECH PROJECT, 2019
** mysh.h
** File description:
** main
*/

#ifndef MYSH_H_
#define MYSH_H_

#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include "my.h"

typedef int (*func)(char **, char ***);

typedef struct link_cmd {
    char *cmd;
    func command;
} cmd_list;

#define CMD_STRUCT {                \
        {"cd", &my_cd},             \
        {"env", &my_env},           \
        {"setenv", &my_setenv},     \
        {"unsetenv", &my_unsetenv}, \
        {"exit", &my_exit},         \
        {NULL, &parse_path}}

#define MY_CD_ARGS_ERROR  \
if (arrlen(arg) > 2) {                       \
    my_puterr("cd: Too many arguments.\n");  \
    return 1;                                \
}

#define MY_CD_DIR_ERROR \
if (status == -1) {                                \
    perror(arg[1]);                                \
    return 1;                                      \
}

#define GET_PATH \
tmp = getcwd(path, 0);         \
path = my_strcat(tmp, "/");    \
free(tmp);

#define SETENV_ERR_ALPHA \
"setenv: Variable name must contain alphanumeric characters.\n"

#define ERR_CMD \
my_puterr(args[0]), my_puterr(": Command not found.\n")

#define ABS(value) ((value < 0) ? -value : value)

char *old_pwd;
int stat_loc;
int status;
pid_t parent_pid;

int my_cd(char **arg, char ***env);
int my_env(char **arg, char ***env);
int my_setenv(char **arg, char ***env);
int my_unsetenv(char **arg, char ***env);
int my_exit(char **arg, char ***env);
char **my_strtoarray(char *str);
char **arraycat(char **dest, char **src);
int arrlen(char **arr);
void free_args(char **args);
int my_isalpha(char c);
int my_isalphanum(char *str);
int my_setenv_error(int argc, char **arg);
void my_insert(char ***arr);
char *getinenv(char const *str, char **env);
int parse_path(char **args, char ***env);
char **my_arrdup(char **env);
int my_puterr(char *str);
char *remove_tabs(char *str);
char *skip_spaces(char *str);
void catch_signal(int signal);
int check_segfault(void);

#endif
