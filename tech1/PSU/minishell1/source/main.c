/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** main
*/

#include "mysh.h"

void catch_signal(int signal)
{
    extern pid_t parent_pid;

    if (SIGTERM == signal) {
        kill(-parent_pid, SIGTERM);
        write(1, "\n", 1);
    } else if (SIGINT == signal && isatty(STDIN_FILENO)) {
        write(0, "\n", 1);
        if (getpid() != parent_pid) {
            my_putstr((status) ? "\e[1;31m¤\e[0m" : " ");
            my_putstr("\e[01;36m[BritiShell] > \e[0m");
        }
    }
}

char *my_prompt(char *line)
{
    size_t nb = 0;
    int len;

    if (isatty(STDIN_FILENO)) {
        my_putstr((status) ? "\e[1;31m¤\e[0m" : " ");
        my_putstr("\e[01;36m[BritiShell] > \e[0m");
    }
    len = getline(&line, &nb, stdin);
    if (len == -1) {
        free(line);
        return NULL;
    }
    line[len - 1] = 0;
    return line;
}

void free_args(char **args)
{
    if (args) {
        for (int i = 0; args[i]; free(args[i]), i++);
        free(args);
    }
}

int my_sh(cmd_list cmd_t[], char ***env, int i)
{
    char *line = NULL;
    char **args = NULL;

    signal(SIGINT, catch_signal), signal(SIGTSTP, catch_signal);
    line = my_prompt(line);
    *env = my_arrdup(*env);
    while (line) {
        line = remove_tabs(line);
        free_args(args);
        args = my_strtoarray(skip_spaces(line));
        free(line);
        if (args) {
            for (i = 0; cmd_t[i].cmd && my_strcmp(cmd_t[i].cmd, args[0]); i++);
            status = cmd_t[i].command(args, env);
        }
        if (i == 4 && status >= 0) break;
        line = my_prompt(line);
    }
    free_args(*env), free(old_pwd), free_args(args);
    return (ABS(status));
}

int main(__attribute__((unused)) int ac,
__attribute__((unused)) char **av, char **env)
{
    cmd_list cmd_t[] = CMD_STRUCT;

    stat_loc = 0;
    status = 0;
    return (my_sh(cmd_t, &env, 0));
}
