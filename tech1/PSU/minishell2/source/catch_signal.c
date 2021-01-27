/*
** EPITECH PROJECT, 2020
** minishell2_tmp
** File description:
** catch_signal
*/

#include "mysh.h"

void catch_signal(int signal)
{
    extern pid_t parent_pid;

    if (SIGINT == signal && isatty(STDIN_FILENO)) {
        write(0, "\n", 1);
        if (getpid() != parent_pid) {
            my_putstr(STATUS_IND);
            my_putstr(PROMPT);
        }
    } else if (SIGTERM == signal) {
        kill(-parent_pid, SIGTERM);
        write(1, "\n", 1);
    }
}
