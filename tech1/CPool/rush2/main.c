/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** rush2
*/

#include "my.h"

float my_count(char *str, char c);
int my_show(char c, int n, float p);
float my_count_alpha(char *str);
int my_language(char *str);
int show_lang(int lang);

int main(int ac, char **av)
{
    int n;
    float p;

    if (my_str_isalpha(av[2]) != 0 || ac < 3){
        write(2, "ERREUR : Pas assez d'arguments", 31);
        return (84);
    }
    for (int i = 2 ; i < ac ; i++) {
        if (my_str_isalpha(av[i]) != 0)
            return (84);
        n = my_count(av[1], av[i][0]);
        p = (n * 100) / my_count_alpha(av[1]);
        my_show(av[i][0], n, p);
    }
    show_lang(my_language(av[1]));
    return (0);
}

int show_lang(int lang)
{
    my_putstr("=> ");
    switch (lang) {
    case 0:
        my_putstr("English");
        break;
    case 1:
        my_putstr("French");
        break;
    case 2:
        my_putstr("Spanish");
        break;
    case 3:
        my_putstr("German");
        break;
    }
    my_putchar('\n');
    return (0);
}

int my_show(char c, int n, float p)
{
    int dec = p * 100;

    my_putchar(c);
    my_putchar(':');
    my_put_nbr(n);
    my_putstr(" (");
    my_put_nbr(p);
    my_putchar('.');
    my_put_nbr(dec % 100);
    my_putstr("%)\n");
    return (0);
}
