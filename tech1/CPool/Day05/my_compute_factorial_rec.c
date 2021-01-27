/*
** EPITECH PROJECT, 2019
** fact recusive
** File description:
** returns factorial with recusion
*/

int my_compute_factorial_rec(int nb)
{
    if (nb > 12 || nb < 0)
        return (0);
    return (fac(nb));
}

int fac(int nb)
{
    if (nb < 2)
        return (1);
    return (nb * fac(nb - 1));
}
