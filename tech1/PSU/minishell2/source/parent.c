/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** parent
*/

#include "mysh.h"

void sig_message3(int sig_stat)
{
    switch (WTERMSIG(sig_stat)) {
    case 29:
        my_puterr("Pollable event occured");
        break;
    default:
        my_puterr(strsignal(WTERMSIG(sig_stat)));
        break;
    }
}

void sig_message2(int sig_stat)
{
    switch (WTERMSIG(sig_stat)) {
    case 16:
        my_puterr("Stack limit exceeded");
        break;
    case 24:
        my_puterr("Cputime limit exceeded");
        break;
    case 25:
        my_puterr("Filesize limit exceeded");
        break;
    case 26:
        my_puterr("Virtual time alarm");
        break;
    case 27:
        my_puterr("Profiling time alarm");
        break;
    default :
        sig_message3(sig_stat);
    }
}

void sig_message(int sig_stat)
{
    switch (WTERMSIG(sig_stat)) {
    case 5:
        my_puterr("Trace/BPT trap");
        break;
    case 6:
        my_puterr("Abort");
        break;
    case 8:
        my_puterr("Floating exception");
        break;
    case 10:
        my_puterr("User signal 1");
        break;
    case 12:
        my_puterr("User signal 2");
        break;
    default:
        sig_message2(sig_stat);
    }
}

int check_segfault(void)
{
    int sig_stat = 0;

    signal(SIGTERM, catch_signal);
    if (-1 == wait(&sig_stat))
        perror("");
    signal(SIGINT, catch_signal);
    if (WIFSIGNALED(sig_stat)) {
        sig_message(sig_stat);
        if (WCOREDUMP(sig_stat))
            my_puterr(" (core dumped)");
        else
            sig_stat += 128;
        my_puterr("\n");
    }
    return sig_stat;
}
