/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** main
*/

#include "mysh.h"

char *my_prompt(char *line)
{
    size_t nb = 0;
    int len;

    if (isatty(STDIN_FILENO)) {
        my_putstr(STATUS_IND);
        my_putstr(PROMPT);
    }
    len = getline(&line, &nb, stdin);
    if (len == -1) {
        free(line);
        return NULL;
    }
    line[len - 1] = 0;
    return line;
}

int shell_loop(char **line, char ***env, cmd_list cmd_t[], int fd_out)
{
    int i = 0;
    char **args = NULL;
    char *next_pipe = get_next(*line, '|');
    pid_t p = 0;

    setup_pipe(next_pipe, 1, fd_out);
    if (next_pipe) p = fork();
    *line = remove_tabs(*line);
    args = my_strtoarray(skip_spaces(*line)), free(*line);
    if (!p && args) {
        for (i = 0; cmd_t[i].cmd && my_strcmp(cmd_t[i].cmd, args[0]); i++);
        status = cmd_t[i].command(args, env);
        dup2(fd_out, 1);
        if (next_pipe) exit(0);
    }
    free_args(args);
    dup2(fd_out, 1);
    if (p) shell_loop(&next_pipe, env, cmd_t, fd_out);
    if (!next_pipe) waitpid(p, &stat_loc, 0), setup_pipe(next_pipe, 0, fd_out);
    return i;
}

void my_sh(char **line, char ***env, cmd_list cmd_t[], int red_fd)
{
    int fds[2] = {dup(0), dup(1)};
    char *next = NULL;
    char *cpy = NULL;
    char **arr = NULL;

    while (*line) {
        fds[0] = dup(fds[0]);
        fds[1] = dup(fds[1]);
        next = get_next(*line, ';');
        cpy = my_strdup(*line);
        arr = my_strtoarray(skip_spaces(remove_tabs(cpy)));
        red_fd = redirection(arr);
        free(cpy), free_args(arr);
        free(get_next(*line, '>')), free(get_next(*line, '<'));
        if (red_fd >= 0 && shell_loop(line, env, cmd_t,
            (red_fd) ?: fds[1]) == 4 && status >= 0) break;
        dup2(fds[0], 0), dup2(fds[1], 1);
        if (red_fd < 0) free(*line);
        *line = (next) ?: my_prompt(*line);
    }
}

int setup(cmd_list cmd_t[], char ***env)
{
    char *line = NULL;

    signal(SIGINT, catch_signal), signal(SIGTSTP, catch_signal);
    line = my_prompt(line);
    *env = my_arrdup(*env);
    my_sh(&line, env, cmd_t, 0);
    free_args(*env), free(old_pwd);
    return (ABS(status));
}

int main(__attribute__((unused)) int ac,
__attribute__((unused)) char **av, char **env)
{
    cmd_list cmd_t[] = CMD_STRUCT;

    stat_loc = 0;
    status = 0;
    return (setup(cmd_t, &env));
}
