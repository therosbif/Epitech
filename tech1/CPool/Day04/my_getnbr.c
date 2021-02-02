/*
** EPITECH PROJECT, 2019
** get nbr
** File description:
** convert str to int
*/

int my_getnbr(char const *str)
{
    int negs = 0;
    long nb = 0;
    int i = 0;

    for (i ; str[i] == '-' || str[i] == '+' ; i++)
        negs += (str[i] == '-');
    for (; str[i] >= '0' && str[i] <= '9' ; i++)
        nb = (nb * 10 + (str[i] - '0'));
    if (negs % 2)
        nb *= -1;
    if (nb >= 2147483647 || nb <= -2147483648)
        return (0);
    return (nb);
}
