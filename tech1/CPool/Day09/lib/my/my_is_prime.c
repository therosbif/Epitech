/*
** EPITECH PROJECT, 2019
** is prime
** File description:
** tests if int is prime
*/

int my_is_prime(int nb)
{
    if (nb < 2)
        return (0);
    for (int i = 2 ; i < nb / 2 + 1 ; i++) {
        if (nb % i == 0)
            return (0);
    }
    return (1);
}
