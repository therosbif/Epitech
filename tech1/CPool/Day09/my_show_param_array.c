/*
** EPITECH PROJECT, 2019
** show param array
** File description:
** show prev finc
*/

#include "my.h"

struct info_param *my_params_to_array(int ac, char **av);

int my_show_param_array(struct info_param const *par)
{
    for (int i = 0 ; par[i].str != 0 ; i++) {
        my_put_nbr(par[i].length);
        my_putchar('\n');
        my_putstr(par[i].str);
        my_putchar('\n');
        my_putstr(par[i].copy);
        my_putchar('\n');
    }
    return (0);
}
