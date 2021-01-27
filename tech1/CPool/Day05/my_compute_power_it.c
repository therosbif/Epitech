/*
** EPITECH PROJECT, 2019
** power it
** File description:
** raise nbr to pwr
*/

int my_compute_power_it(int nb, int p)
{
    long n = nb;

    if (p == 0)
        return (1);
    for (p ; p >= 2 ; p--)
        n *= nb;
    if (n > 2147483647 || n < -2147483648 || p < 0)
        return (0);
    return (n);
}
