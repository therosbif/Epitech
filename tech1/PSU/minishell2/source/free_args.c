/*
** EPITECH PROJECT, 2020
** minishell2_tmp
** File description:
** free_args
*/

#include "mysh.h"

void free_args(char **args)
{
    if (args) {
        for (int i = 0; args[i]; free(args[i]), i++);
        free(args);
    }
}
