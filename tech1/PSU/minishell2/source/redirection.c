/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** redirection
*/

#include "mysh.h"

int find_chevron(char **args, char **file)
{
    char *chevron[] = {"<", "<<", ">", ">>", NULL};

    for (; args && *args; args++) {
        for (int i = 0; chevron[i]; i++)
            if (!my_strcmp(*args, chevron[i])) {
                *file = *(++args);
                return i + 1;
            }
    }
    return 0;
}

int red_stdin(char *delim)
{
    char buff[51];
    int len = 0;
    int fd[2];

    pipe(fd);
    buff[0] = '\0';
    while (my_strcmp(buff, delim)) {
        if ((len = read(0, buff, 50)) < 0) {
            write(2, "Error with read\n", 17);
            return -1;
        } if (len)
            buff[len - 1] = 0;
        if (my_strcmp(buff, delim)) {
            write(fd[1], buff, my_strlen(buff));
            write(fd[1], "\n", 1);
        }
    }
    close(fd[1]);
    dup2(fd[0], 0);
    close(fd[0]);
    return 0;
}

int my_perror(char *file)
{
    perror(file);
    return -1;
}

int redirection(char **args)
{
    char *file = NULL;
    int red = find_chevron(args, &file);
    int fd = -1;

    if (!file && red)
        return (write(2, "Missing name for redirect.\n", 28) - 29);
    if (red > 2) {
        fd = open(file, REDOUT_FLAGS, 0644);
        if (fd == -1) return my_perror(file);
        dup2(fd, 1);
    } else if (red) {
        if (red == 2) return red_stdin(file);
        fd = open(file, O_RDONLY);
        if (fd == -1) return my_perror(file);
        dup2(fd, 0);
    }
    return (file) ? fd : 0;
}
