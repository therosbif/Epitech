/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** cd_error
*/

#include "mysh.h"

void cd_error(char *path, char *dir)
{
    struct stat file;

    lstat(path, &file);
    my_puterr(dir);
    if (access(path, F_OK) == 0)
        my_puterr((S_ISDIR(file.st_mode) != 1) ?
            ": Not a directory.\n" : ": Permission denied.\n");
    else my_puterr(": Not a directory.\n");
}
