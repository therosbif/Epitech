/*
** EPITECH PROJECT, 2019
** find prime
** File description:
** finds smallest prime above int
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    for ( ; !(my_is_prime(nb)) ; nb++);
    return (nb);
}
