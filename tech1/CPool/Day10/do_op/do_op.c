/*
** EPITECH PROJECT, 2019
** do op 
** File description:
** do op
*/

#include "my.h"
#include "op.h"
#include <stddef.h>

int calculate(int a, int b, char *op)
{
    switch(op[0]) {
    case '+':
        return (success(SUM(a, b)));
    case '-':
        return (success(DIFF(a, b)));
    case '*':
        return (success(PROD(a, b)));
    case '/':
        if (b == 0)
            my_putstr("Stop: division by zero\n");
        return ((b == 0) ? 84 : success(QUOT(a, b)));
    case '%':
        if (b == 0)
            my_putstr("Stop: modulo by zero\n");
        return ((b == 0) ? 84 : success(MOD(a, b)));
    default :
        write(1, '0', 1);
        my_putchar('\n');
        return (84);
    }
}

int success(int a)
{
    my_put_nbr(a);
    my_putchar('\n');
    return (0);
}

int main(int ac, char **av)
{
    int a;
    int b;

    if (ac != 4)
        return (84);
    a = my_getnbr(av[1]);
    b = my_getnbr(av[3]);
    return (calculate(a, b, av[2]));
}
