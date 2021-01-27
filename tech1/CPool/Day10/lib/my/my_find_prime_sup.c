/*
** EPITECH PROJECT, 2019
** find prime
** File description:
** finds smallest prime above int
*/

int my_find_prime_sup(int nb)
{
    while (nb < 2147483648) {
        if (my_is_prime(nb))
            return (nb);
        nb++;
    }
    return (0);
}
