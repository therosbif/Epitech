/*
** EPITECH PROJECT, 2019
** project
** File description:
** .
*/

#include "my_ls.h"

flags_t *init_flags(void)
{
    flags_t *flags = malloc(sizeof(flags_t));

    flags->l = 0;
    flags->r = 0;
    flags->d = 0;
    flags->t = 0;
    flags->_r = 0;
    flags->a = 0;
    flags->total = 0;
    return flags;
}

flags_t *set_flags(char **av)
{
    flags_t *flags = init_flags();
    int valid = 0;

    for (int i = 1; i < my_ac(0); i++) {
        for (int j = 1; av[i][0] == '-' && av[i][j]; j++, valid = 0) {
            (av[i][j] == 'l') ? flags->l = 1, (valid = 1) : 1;
            (av[i][j] == 'd') ? flags->d = 1, (valid = 1) : 1;
            (av[i][j] == 'r') ? flags->r = 1, (valid = 1) : 1;
            (av[i][j] == 'R') ? flags->_r = 1, (valid = 1) : 1;
            (av[i][j] == 't') ? flags->t = 1, (valid = 1) : 1;
            (av[i][j] == 'a') ? flags->a = 1, (valid = 1) : 1;
            if (!valid){
                write(2, "ERROR: Invalid flag\n", 21);
                exit(84);
            }
        }
    }
    return flags;
}
