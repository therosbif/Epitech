/*
** EPITECH PROJECT, 2019
** sqr
** File description:
** sqr an int
*/

int my_compute_square_root(int nb)
{
    int i = 0;

    for (i ; i * i < nb ; i++) {}
    if (i * i == nb)
        return (i);
    return (0);
}
