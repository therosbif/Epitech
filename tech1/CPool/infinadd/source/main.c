/*
** EPITECH PROJECT, 2019
** main
** File description:
** infinadd
*/

#include <stdlib.h>
#include "my.h"
#include "struct_opps.h"

void addup(digits **result, char *num1, char *num2);
int subtract(digits **result, char *num1, char *num2);

int my_put_in_list(digits **result, char data)
{
    digits *element = malloc(sizeof(*element));

    element->c = data;
    element->next = *result;
    *result = element;
    return (0);
}

void my_show_list(digits *result)
{
    digits *tmp = result;
    char begin = 0;

    while (tmp) {
        if (tmp->c != '0' || begin == 1 || tmp->next == NULL) {
            begin = (tmp->c == '-') ? 0 : 1;
            my_putchar(tmp->c);
        }
        tmp = tmp->next;
    }
    my_putchar('\n');
}

int main(int ac, char **av)
{
    int opp = 1;
    digits *result = NULL;

    if (ac != 3)
        return 84;
    if (my_str_isnum(av[1]) == 1 || my_str_isnum(av[2]) == 1)
        return 84;
    opp *= GET_SIGN(av[1]) * GET_SIGN(av[2]);
    if (opp == 1) {
        if (GET_SIGN(av[1]) == -1) {
            addup(&result, av[1] + 1, av[2] + 1);
            my_put_in_list(&result, '-');
        } else
            addup(&result, av[1], av[2]);
    }
    else if (subtract(&result, av[1], av[2]) == -1 && result->c != '0')
        my_put_in_list(&result, '-');
    my_show_list(result);
    return (0);
}
