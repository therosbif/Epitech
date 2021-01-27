/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** pipe
*/

#include "mysh.h"

void setup_pipe(char *next, int i, int fd_out)
{
    static int filedes[2];
    int fd = filedes[0];

    if (i) {
        if (filedes[1]) close(filedes[1]);
        dup2(fd, 0);
        if (next) {
            pipe(filedes);
            dup2(filedes[1], 1);
        } else dup2(fd_out, 1);
    } else {
        if (!next)
            filedes[0] = 0, filedes[1] = 0;
        close(filedes[0]);
        dup2(fd_out, 1);
    }
}
