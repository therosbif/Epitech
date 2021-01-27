/*
** EPITECH PROJECT, 2019
** project
** File description:
** .
*/

int my_nlen(int n)
{
    int i = 0;

    for (; n; n /= 10, i++);
    if (i == 0) i = 1;
    return i;
}
