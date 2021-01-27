/*
** EPITECH PROJECT, 2019
** factorial
** File description:
** returns factorial of an int
*/

int my_compute_factorial_it(int nb)
{
    int result = 1;

    if (nb > 12 || nb < 0)
        return (0);
    for (nb ; nb > 0 ; nb--)
        result *= nb;
    return (result);
}
