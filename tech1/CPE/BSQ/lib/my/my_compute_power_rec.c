/*
** EPITECH PROJECT, 2019
** power rec
** File description:
** returns a**b rec
*/

long powerrec(long nb, int p)
{
    if (p < 1)
        return (1);
    p--;
    return (nb * powerrec(nb, p));
}

int my_power_rec(int nb, int p)
{
    long n = nb;

    if (p == 0)
        return (1);
    n = powerrec(n, p);
    if (n > 2147483647 || n < -2147483648 || p < 0)
        return (0);
    return (n);
}
