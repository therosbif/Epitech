/*
** EPITECH PROJECT, 2019
** stumper
** File description:
** final stumper
*/

#include <unistd.h>
#include "my.h"

void put_xy(int x, int y)
{
    my_put_nbr(x);
    my_putchar(32);
    my_put_nbr(y);
}

void case_345(int x, int y, char *buff)
{
    if (x == 1 || y == 1) {
        my_putstr("[rush1-3] ");
        put_xy(x, y);
        my_putstr(" || [rush1-4] ");
        put_xy(x, y);
        my_putstr(" || [rush1-5] ");
        put_xy(x, y);
    }
    else if(buff[x - 1] == 'A') {
        my_putstr("[rush1-3] ");
        put_xy(x, y);
    }
    else if(buff[x * y - 1] == 'C') {
        my_putstr("[rush1-5] ");
        put_xy(x, y);
    } else {
        my_putstr("[rush1-4] ");
        put_xy(x, y);
    }
    my_putchar('\n');
}

void rush3(char *buff)
{
    int x = 0;
    int y = 0;
    
    for (; buff[x] != '\n' && buff[x] != '\0' ; x++);
    for (int i = 0 ; buff[i] != '\0' ; i++)
        y += (buff[i] == '\n') ? 1 : 0;
    if (buff[0] == 'o') {
        my_putstr("[rush1-1] ");
	put_xy(x, y);
	my_putchar('\n');
    }
    else if (buff[0] == '/' || buff[0] == '*') {
        my_putstr("[rush1-2] ");
	put_xy(x, y);
	my_putchar('\n');
    }
    else if (buff[0] == 'A' || buff[0] == 'B')
        case_345(x, y, buff);
    else
        my_putstr("null\n");
}
